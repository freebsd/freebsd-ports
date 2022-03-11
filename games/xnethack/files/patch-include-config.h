--- include/config.h.orig	2022-03-07 23:57:15 UTC
+++ include/config.h
@@ -303,11 +303,11 @@
 
 #if defined(UNIX) && !defined(ZLIB_COMP) && !defined(COMPRESS)
 /* path and file name extension for compression program */
-#define COMPRESS "/usr/bin/compress" /* Lempel-Ziv compression */
-#define COMPRESS_EXTENSION ".Z"      /* compress's extension */
+/* #define COMPRESS "/usr/bin/compress" */ /* Lempel-Ziv compression */
+/* #define COMPRESS_EXTENSION ".Z"      */ /* compress's extension */
 /* An example of one alternative you might want to use: */
-/* #define COMPRESS "/usr/local/bin/gzip" */ /* FSF gzip compression */
-/* #define COMPRESS_EXTENSION ".gz" */       /* normal gzip extension */
+#define COMPRESS "/usr/bin/gzip" /* FSF gzip compression */
+#define COMPRESS_EXTENSION ".gz"       /* normal gzip extension */
 #endif
 
 #ifndef COMPRESS
@@ -392,7 +392,7 @@
  * otherwise it will be the current directory.
  */
 #ifndef HACKDIR
-#define HACKDIR "/usr/games/lib/xnethackdir"
+#define HACKDIR "%%HACKDIR%%"
 #endif
 
 /*
@@ -653,7 +653,7 @@ typedef unsigned char uchar;
 #ifdef DUMPLOG
 
 #ifndef DUMPLOG_FILE
-#define DUMPLOG_FILE        "/tmp/xnethack.%n.%d.log"
+#define DUMPLOG_FILE        "/tmp/xnethack.%v.%u.%n.%D.log"
 /* DUMPLOG_FILE allows following placeholders:
    %% literal '%'
    %v version (eg. "3.6.3-0")
