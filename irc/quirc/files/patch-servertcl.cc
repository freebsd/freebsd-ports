--- servertcl.cc.orig	Thu May 22 14:12:56 2003
+++ servertcl.cc	Thu May 22 14:13:04 2003
@@ -1,3 +1,4 @@
+#include <ctype.h>
 #include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -877,7 +878,7 @@ int TT_Proc___template__script(TT_PROC_A
   twindow *windowp;
   char temp[TEMPLEN];
   char assemble[TEMPLEN];
-  char *pos;
+  const char *pos;
   const char *afterslash;
   int n;
   if(argc>=3) {
@@ -997,7 +998,7 @@ int TT_Proc___template__unscript(TT_PROC
   twindow *windowp;
   char temp[TEMPLEN];
   char storage[TEMPLEN];
-  char *pos;
+  const char *pos;
   const char *afterslash;
   int n;
   if(argc>=3) {
