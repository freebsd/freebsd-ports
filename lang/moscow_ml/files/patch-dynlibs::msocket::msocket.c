--- dynlibs/msocket/msocket.c.orig	Fri Jan 21 15:37:13 2000
+++ dynlibs/msocket/msocket.c	Sun Jun  9 12:40:19 2002
@@ -469,6 +469,7 @@
 EXTERNML value msocket_bind(value socket, value address) {
   int ret, size;
   union saddr addr;
+  bzero(&addr, sizeof(addr));
   make_saddr(&addr, address);
   size  = Int_val(Size_addrval(address));
   ret = bind(Sock_val(socket), &addr.sockaddr_gen, size);
@@ -486,6 +487,7 @@
   int ret, size;
   union saddr addr;
  
+  bzero(&addr, sizeof(addr));
   make_saddr(&addr, address);
   size  = Int_val(Size_addrval(address));
 
@@ -572,6 +574,7 @@
   signal(SIGPIPE, SIG_IGN);
 #endif
  
+  bzero(&addr, sizeof(addr));
   make_saddr(&addr, address);
   enter_blocking_section();
   ret = sendto(Sock_val(sock), &Byte(buff, Long_val(Field(tup,0))), 
