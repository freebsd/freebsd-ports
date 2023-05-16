--- util/makedefs.c.orig	2023-05-16 21:33:58 UTC
+++ util/makedefs.c
@@ -113,6 +113,7 @@ static struct version_info version;
 #define MAXFNAMELEN 600
 
 static char filename[MAXFNAMELEN];
+static char tempfilename[MAXFNAMELEN];
 
 #ifdef FILE_PREFIX
 /* if defined, a first argument not starting with - is
@@ -244,6 +245,12 @@ main(int argc, char *argv[])
         /*NOTREACHED*/
     }
 
+    if (snprintf(tempfilename, sizeof(tempfilename), "%s.%d", "grep.tmp", getpid()) >= sizeof(tempfilename)) {
+        Fprintf(stderr, "Cannot create temporary filename.");
+        (void) fflush(stderr);
+        return 1;
+    }
+
 #ifdef FILE_PREFIX
     if (argc >= 2 && argv[1][0] != '-') {
         file_prefix = argv[1];
@@ -1041,12 +1048,12 @@ do_rnd_access_file(
         Strcat(buf, "\n"); /* so make sure that the default one does too    */
     (void) fputs(xcrypt(padline(buf, padlength)), ofp);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE, FLG_TEMPFILE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE, FLG_TEMPFILE);
     grep0(ifp, tfp, FLG_TEMPFILE);
 #ifndef HAS_NO_MKSTEMP
     ifp = tfp;
 #else
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE, 0);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE, 0);
 #endif
     while ((line = fgetline(ifp)) != 0) {
         if (line[0] != '#' && line[0] != '\n') {
@@ -1059,7 +1066,7 @@ do_rnd_access_file(
     Fclose(ofp);
 
 #ifdef HAS_NO_MKSTEMP
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, templfilename);
 #endif
     return;
 }
@@ -1874,12 +1881,12 @@ do_dungeon(void)
     }
     Fprintf(ofp, "%s", Dont_Edit_Data);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE, FLG_TEMPFILE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE, FLG_TEMPFILE);
     grep0(ifp, tfp, FLG_TEMPFILE);
 #ifndef HAS_NO_MKSTEMP
     ifp = tfp;
 #else
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE, 0);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE, 0);
 #endif
     while ((line = fgetline(ifp)) != 0) {
         SpinCursor(3);
@@ -1895,7 +1902,7 @@ do_dungeon(void)
     Fclose(ofp);
 
 #ifdef HAS_NO_MKSTEMP
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
 #endif
     return;
 }
