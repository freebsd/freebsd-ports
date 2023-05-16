--- include/config.h.orig	2023-05-16 21:33:58 UTC
+++ include/config.h
@@ -312,11 +312,11 @@
 
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
@@ -401,7 +401,7 @@
  * otherwise it will be the current directory.
  */
 #ifndef HACKDIR
-#define HACKDIR "/usr/games/lib/xnethackdir"
+#define HACKDIR "%%HACKDIR%%"
 #endif
 
 /*
@@ -662,7 +662,7 @@ typedef unsigned char uchar;
 
 /* TEMPORARY - MAKE UNCONDITIONAL BEFORE RELEASE */
 /* undef this to check if sandbox breaks something */
-#define NHL_SANDBOX
+/* #define NHL_SANDBOX */
 
 /* End of Section 4 */
 
@@ -691,7 +691,7 @@ typedef unsigned char uchar;
 #define DUMPLOG_MSG_COUNT   50
 #endif /* DUMPLOG_MSG_COUNT */
 #ifndef DUMPLOG_FILE
-#define DUMPLOG_FILE        "/tmp/xnethack.%n.%d.log"
+#define DUMPLOG_FILE        "/tmp/xnethack.%v.%u.%n.%D.log"
 /* DUMPLOG_FILE allows following placeholders:
    %% literal '%'
    %v version (eg. "3.6.3-0")
@@ -720,7 +720,7 @@ typedef unsigned char uchar;
 
 /* TEMPORARY - MAKE UNCONDITIONAL BEFORE RELEASE */
 /* undef this to check if sandbox breaks something */
-#define NHL_SANDBOX
+/* #define NHL_SANDBOX */
 
 /* End of Section 4 */
 
