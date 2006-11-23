--- main/socket.cc.orig	Sun Apr  9 13:39:25 2006
+++ main/socket.cc	Thu Nov 23 03:30:12 2006
@@ -112,7 +112,7 @@
 
 unsigned int tSocket::get_addr() {
 	unsigned int my_addr=0;
-#if defined(__sparc__) && !(defined(__linux__))
+#if defined(__sparc__) && !(defined(__linux__)) && !(defined(BSD))
 	int len;
 #else
 	socklen_t len;
@@ -271,7 +271,7 @@
 int tSocket::accepting(const char * host) {
 	DBC_RETVAL_IF_FAIL(host!=NULL,-1);
 	sockaddr_in addr;
-#if defined(__sparc__) && !(defined(__linux__))
+#if defined(__sparc__) && !(defined(__linux__)) && !(defined(BSD))
 	int len=sizeof(addr);
 #else
 	socklen_t len=sizeof(addr);
