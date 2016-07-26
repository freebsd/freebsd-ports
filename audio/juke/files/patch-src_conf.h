--- src/conf.h.orig	1999-04-07 17:47:53 UTC
+++ src/conf.h
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
