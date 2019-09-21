--- util/makedefs.c.orig	2019-05-08 00:00:16.000000000 -0700
+++ util/makedefs.c	2019-05-16 08:21:09.868001000 -0700
@@ -139,6 +139,7 @@
 #define MAXFNAMELEN 600
 
 static char filename[MAXFNAMELEN];
+static char tempfilename[MAXFNAMELEN];
 
 #ifdef FILE_PREFIX
 /* if defined, a first argument not starting with - is
@@ -272,6 +273,12 @@
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
@@ -967,9 +974,9 @@
     }
     Fprintf(ofp, "%s", Dont_Edit_Data);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE);
     grep0(ifp, tfp);
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE);
 
     while ((line = fgetline(ifp)) != 0) {
         if (line[0] != '#' && line[0] != '\n')
@@ -979,7 +986,7 @@
     Fclose(ifp);
     Fclose(ofp);
 
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
     return;
 }
 
@@ -2230,9 +2237,9 @@
     }
     Fprintf(ofp, "%s", Dont_Edit_Data);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE);
     grep0(ifp, tfp);
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE);
 
     while ((line = fgetline(ifp)) != 0) {
         SpinCursor(3);
@@ -2247,7 +2254,7 @@
     Fclose(ifp);
     Fclose(ofp);
 
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
     return;
 }
 
