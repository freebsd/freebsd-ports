--- include/config.h.orig	2026-02-28 22:45:03 UTC
+++ include/config.h
@@ -387,11 +387,11 @@
 
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
@@ -444,7 +444,7 @@
  * otherwise it will be the current directory.
  */
 #ifndef HACKDIR
-#define HACKDIR "/usr/games/lib/xnethackdir"
+#define HACKDIR "%%HACKDIR%%"
 #endif
 
 /*
@@ -699,7 +699,7 @@ typedef unsigned char uchar;
 
 /* TEMPORARY - MAKE UNCONDITIONAL BEFORE RELEASE */
 /* undef this to check if sandbox breaks something */
-#define NHL_SANDBOX
+/* #define NHL_SANDBOX */
 
 #ifdef NHL_SANDBOX
 #ifdef CHRONICLE
@@ -733,7 +733,7 @@ typedef unsigned char uchar;
 #ifdef DUMPLOG
 #define DUMPLOG_CORE
 #ifndef DUMPLOG_FILE
-#define DUMPLOG_FILE        "/tmp/xnethack.%n.%d.log"
+#define DUMPLOG_FILE        "/tmp/xnethack.%v.%u.%n.%D.log"
 /* DUMPLOG_FILE allows following placeholders:
    %% literal '%'
    %v version (eg. "3.6.3-0")
@@ -769,7 +769,7 @@ typedef unsigned char uchar;
 
 /* TEMPORARY - MAKE UNCONDITIONAL BEFORE RELEASE */
 /* undef this to check if sandbox breaks something */
-#define NHL_SANDBOX
+/* #define NHL_SANDBOX */
 
 /* End of Section 4 */
 
