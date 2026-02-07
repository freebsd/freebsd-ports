libc++ doesn't like "using namespace std" in C++11

Communicator.cxx:139:73: error: invalid operands to binary expression ('__bind<int &, sockaddr *, unsigned long>' and 'int')
    if (bind(connection_socket, (sockaddr *) &address, sizeof(address)) < 0) {
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^ ~

--- src/Communicator.cxx.orig	2005-04-16 08:13:38 UTC
+++ src/Communicator.cxx
@@ -136,7 +136,7 @@ void Communicator::initialize ( int mode, int port, ch
     address.sin_addr.s_addr = htonl(INADDR_ANY);
     address.sin_port = htons(port);
 
-    if (bind(connection_socket, (sockaddr *) &address, sizeof(address)) < 0) {
+    if (::bind(connection_socket, (sockaddr *) &address, sizeof(address)) < 0) {
       cerr << "Port " << port << " is busy." << endl;
       exit(1);
     }
