--- memcachedb.h.orig	2007-09-22 04:01:02.000000000 +0800
+++ memcachedb.h	2007-09-22 04:01:15.000000000 +0800
@@ -40,8 +40,8 @@
 extern struct stats stats;
 extern struct settings settings;
 
-#define END_LEN 32
-#define END_LEN_STR "31"
+#define END_LEN 128
+#define END_LEN_STR "127"
 
 typedef struct _stritem {
     int nbytes;			/* size of data */
