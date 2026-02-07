libc++ doesn't like "using namespace std" in C++11

server.cc:125:68: error: invalid operands to binary expression ('__bind<int &, sockaddr *, unsigned
      long>' and 'int')
    if (bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~

--- festival/src/arch/festival/server.cc.orig	2005-10-26 19:44:06 UTC
+++ festival/src/arch/festival/server.cc
@@ -122,7 +122,7 @@ int festival_start_server(int port)
     serv_addr.sin_port = htons(port);
     serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
 
-    if (bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
+    if (::bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
     {
 	cerr << "socket: bind failed" << endl;
 	festival_error();
