--- util/makedefs.c.orig	2020-04-04 00:36:25.595499000 -0700
+++ util/makedefs.c	2020-04-04 00:42:25.126524000 -0700
@@ -139,6 +139,7 @@
 #define MAXFNAMELEN 600
 
 static char filename[MAXFNAMELEN];
+static char tempfilename[MAXFNAMELEN];
 
 #ifdef FILE_PREFIX
 /* if defined, a first argument not starting with - is
@@ -279,6 +280,12 @@
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
@@ -993,9 +1000,9 @@
        more likely to be picked than normal but it's nothing to worry about */
     (void) fputs(xcrypt(deflt_content), ofp);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE);
     grep0(ifp, tfp);
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE);
 
     while ((line = fgetline(ifp)) != 0) {
         if (line[0] != '#' && line[0] != '\n')
@@ -1005,7 +1012,7 @@
     Fclose(ifp);
     Fclose(ofp);
 
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
     return;
 }
 
@@ -2291,9 +2298,9 @@
     }
     Fprintf(ofp, "%s", Dont_Edit_Data);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE);
     grep0(ifp, tfp);
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE);
 
     while ((line = fgetline(ifp)) != 0) {
         SpinCursor(3);
@@ -2308,7 +2315,7 @@
     Fclose(ifp);
     Fclose(ofp);
 
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
     return;
 }
 
