communication.cpp:108:32: error: invalid operands to binary expression ('__bind<int &, sockaddr *, unsigned int>' and 'int')
                          sizeof (struct sockaddr)) == -1)
                          ~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~

--- communication.cpp.orig	2018-08-26 18:50:21 UTC
+++ communication.cpp
@@ -104,7 +104,7 @@ bool Communicator::setup_socket_server(string port_str
   memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
 
   /* bind */
-  if (bind(socket_fd, (struct sockaddr *)&my_addr, 
+  if (::bind(socket_fd, (struct sockaddr *)&my_addr, 
 			  sizeof (struct sockaddr)) == -1)
 	 {
 		MAKE_ERROR(string("bind: ")+string(strerror(errno))+string(".\n"));
