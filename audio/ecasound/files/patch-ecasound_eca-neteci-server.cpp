libc++ doesn't like "using namespace std" in C++11

eca-neteci-server.cpp:179:11: error: assigning to 'int' from incompatible type '__bind<int &,
      sockaddr *, unsigned long>'
    res = bind(srvfd_rep, (struct sockaddr*)&addr_un_rep, sizeof(addr_un_rep));
          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
eca-neteci-server.cpp:181:11: error: assigning to 'int' from incompatible type '__bind<int &,
      sockaddr *, unsigned long>'
    res = bind(srvfd_rep, (struct sockaddr*)&addr_in_rep, sizeof(addr_in_rep));
          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- ecasound/eca-neteci-server.cpp.orig	2011-04-05 20:36:01 UTC
+++ ecasound/eca-neteci-server.cpp
@@ -176,9 +176,9 @@ void ECA_NETECI_SERVER::open_server_socket(void)
   
   int res = 0;
   if (unix_sockets_rep == true) 
-    res = bind(srvfd_rep, (struct sockaddr*)&addr_un_rep, sizeof(addr_un_rep));
+    res = ::bind(srvfd_rep, (struct sockaddr*)&addr_un_rep, sizeof(addr_un_rep));
   else
-    res = bind(srvfd_rep, (struct sockaddr*)&addr_in_rep, sizeof(addr_in_rep));
+    res = ::bind(srvfd_rep, (struct sockaddr*)&addr_in_rep, sizeof(addr_in_rep));
   
   if (res == 0) {
     res = listen(srvfd_rep, 5);
