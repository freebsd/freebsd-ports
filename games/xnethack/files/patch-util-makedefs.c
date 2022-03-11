--- util/makedefs.c.orig	2022-03-07 23:57:15 UTC
+++ util/makedefs.c
@@ -116,6 +116,7 @@ static struct version_info version;
 #define MAXFNAMELEN 600
 
 static char filename[MAXFNAMELEN];
+static char tempfilename[MAXFNAMELEN];
 
 #ifdef FILE_PREFIX
 /* if defined, a first argument not starting with - is
@@ -230,6 +231,12 @@ main(int argc, char *argv[])
         return 1;
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
@@ -989,12 +996,12 @@ do_rnd_access_file(
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
@@ -1007,7 +1014,7 @@ do_rnd_access_file(
     Fclose(ofp);
 
 #ifdef HAS_NO_MKSTEMP
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, templfilename);
 #endif
     return;
 }
@@ -1791,12 +1798,12 @@ do_dungeon(void)
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
@@ -1812,7 +1819,7 @@ do_dungeon(void)
     Fclose(ofp);
 
 #ifdef HAS_NO_MKSTEMP
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
 #endif
     return;
 }
