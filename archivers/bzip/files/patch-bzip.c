--- bzip.c.orig	1996-08-30 20:35:28.000000000 +0000
+++ bzip.c
@@ -114,9 +114,13 @@
 --*/
 
 #if BZ_UNIX_32
+   #include <sys/types.h>
    #include <utime.h>
    #include <unistd.h>
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) \
+ && !defined(__DragonFly__)	/* stdlib already included above */
    #include <malloc.h>
+#endif
    #include <sys/stat.h>
    #include <sys/times.h>
 
@@ -2578,7 +2582,7 @@ void bitStreamEOF ()
 
 
 /*---------------------------------------------*/
-void mySignalCatcher ( IntNative *n )
+void mySignalCatcher (int n __unused)
 {
    fprintf ( stderr, 
              "\n%s: Control-C (or similar) caught, quitting.\n",
@@ -2588,7 +2592,7 @@ void mySignalCatcher ( IntNative *n )
 
 
 /*---------------------------------------------*/
-void mySIGSEGVorSIGBUScatcher ( IntNative *n )
+void mySIGSEGVorSIGBUScatcher (int n __unused)
 {
    if (compressing)
       fprintf ( stderr,
@@ -3130,11 +3134,6 @@ IntNative main ( IntNative argc, Char *a
    signal (SIGBUS,  mySIGSEGVorSIGBUScatcher);
    #endif
 
-   if ( ! (argc > 1 && strcmp ( "-Q", argv[1] ) == 0) )
-      fprintf ( stderr,
-                "BZIP, a block-sorting file compressor.  "
-                "Version 0.21, 25-August-96.\n" );
-
    #if DEBUG
       if ( ! (argc > 1 && strcmp ( "-Q", argv[1] ) == 0) )
          fprintf ( stderr, "BZIP: *** compiled with debugging ON ***\n" );
@@ -3205,6 +3204,12 @@ IntNative main ( IntNative argc, Char *a
                          break;
          }
 
+   if (verbose) {
+      fprintf ( stderr,
+                "BZIP, a block-sorting file compressor.  "
+                "Version 0.21, 25-August-96.\n" );
+   }
+
    if ( opMode == OM_FILE_TO_STDOUT && numFileNames != 1) {
       fprintf ( stderr, "%s: Option -c requires you to supply exactly one filename.\n",
                 progName );
