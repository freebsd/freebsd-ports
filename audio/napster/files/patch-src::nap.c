--- src/nap.c.orig	Thu Jul 17 20:21:08 2003
+++ src/nap.c	Thu Jul 17 20:22:02 2003
@@ -542,21 +542,20 @@
 
   if (!getval("connection")) {
     if (!info.daemon) {
-      wp(NULL, "
-          Connection | Number
-          -------------------
-          Unknown    |  0
-          14.4       |  1
-          28.8       |  2
-          33.6       |  3
-          56.7       |  4
-          64K ISDN   |  5
-          128K ISDN  |  6
-          Cable      |  7
-          DSL        |  8
-          T1         |  9
-          T3 or >    | 10
-\n");
+      wp(NULL, "\
+          Connection | Number\n\
+          -------------------\n\
+          Unknown    |  0\n\
+          14.4       |  1\n\
+          28.8       |  2\n\
+          33.6       |  3\n\
+          56.7       |  4\n\
+          64K ISDN   |  5\n\
+          128K ISDN  |  6\n\
+          Cable      |  7\n\
+          DSL        |  8\n\
+          T1         |  9\n\
+          T3 or >    | 10\n");
       wp(NULL, "How fast is your internet connection?\n");
       wp(NULL, "Please choose 0--10 from the chart: [4] ");
       ans = nap_getline(stdin);
