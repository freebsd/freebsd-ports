--- util/makedefs.c.orig	2015-11-09 11:13:10 UTC
+++ util/makedefs.c
@@ -135,6 +135,7 @@
 /*-end of vision defs-*/
 
 static char filename[600];
+static char tempfilename[600];  /* grep.tmp.<pid> */
 
 #ifdef FILE_PREFIX
 /* if defined, a first argument not starting with - is
@@ -261,6 +262,12 @@
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
@@ -949,9 +956,9 @@
     }
     Fprintf(ofp, "%s", Dont_Edit_Data);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE);
     grep0(ifp, tfp);
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE);
 
     while ((line = fgetline(ifp)) != 0) {
         if (line[0] != '#' && line[0] != '\n')
@@ -961,7 +968,7 @@
     Fclose(ifp);
     Fclose(ofp);
 
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
     return;
 }
 
@@ -1955,9 +1962,9 @@
     }
     Fprintf(ofp, "%s", Dont_Edit_Data);
 
-    tfp = getfp(DATA_TEMPLATE, "grep.tmp", WRTMODE);
+    tfp = getfp(DATA_TEMPLATE, tempfilename, WRTMODE);
     grep0(ifp, tfp);
-    ifp = getfp(DATA_TEMPLATE, "grep.tmp", RDTMODE);
+    ifp = getfp(DATA_TEMPLATE, tempfilename, RDTMODE);
 
     while ((line = fgetline(ifp)) != 0) {
         SpinCursor(3);
@@ -1973,7 +1980,7 @@
     Fclose(ifp);
     Fclose(ofp);
 
-    delete_file(DATA_TEMPLATE, "grep.tmp");
+    delete_file(DATA_TEMPLATE, tempfilename);
     return;
 }
 
