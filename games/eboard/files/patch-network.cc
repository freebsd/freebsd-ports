
$FreeBSD$

--- network.cc.orig	Sat Jul  6 23:05:11 2002
+++ network.cc	Sat Sep 28 23:00:20 2002
@@ -26,6 +26,7 @@
 
 
 #include <iostream.h>
+#include <arpa/inet.h>
 #include <time.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -135,7 +136,7 @@
   return(strstr(dump,match)!=0);
 }
 
-int BufferedConnection::consume(int handle, int amount=128) {
+int BufferedConnection::consume(int handle, int amount) {
   int i,j;
   char sm[2048];
   if (amount>2048) amount=2048;
