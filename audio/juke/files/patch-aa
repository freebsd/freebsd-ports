--- ../juke.orig/src/conf.h	Thu Apr 15 21:44:53 1999
+++ ./src/conf.h	Sun May  2 12:16:58 1999
@@ -1,6 +1,11 @@
 #define CFG_ARGS     10
 #define CFG_STRLEN  100
 
+#ifndef PREFIX
+#define PREFIX "/usr/local"
+#endif
+#define CFG_RCFILE PREFIX "/etc/juke.conf"
+
 struct CFG_FORMAT {
   int args;
   int match_len;
