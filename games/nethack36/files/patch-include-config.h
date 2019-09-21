--- include/config.h.orig	2018-04-27 05:07:22.000000000 -0700
+++ include/config.h	2019-04-26 07:32:12.113908000 -0700
@@ -256,11 +256,11 @@
 
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
@@ -345,7 +345,7 @@
  * otherwise it will be the current directory.
  */
 #ifndef HACKDIR
-#define HACKDIR "/usr/games/lib/nethackdir"
+#define HACKDIR "%%PREFIX%%/share/nethack"
 #endif
 
 /*
@@ -520,7 +520,7 @@
    (within the same session) */
 /* #define EDIT_GETLIN */
 
-/* #define DUMPLOG */  /* End-of-game dump logs */
+#define DUMPLOG /* End-of-game dump logs */
 #ifdef DUMPLOG
 
 #ifndef DUMPLOG_MSG_COUNT
@@ -528,7 +528,7 @@
 #endif
 
 #ifndef DUMPLOG_FILE
-#define DUMPLOG_FILE        "/tmp/nethack.%n.%d.log"
+#define DUMPLOG_FILE        "/tmp/nethack.%v.%u.%n.%D.log"
 /* DUMPLOG_FILE allows following placeholders:
    %% literal '%'
    %v version (eg. "3.6.1-0")
