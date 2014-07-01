--- libfind2.c.orig	2014-06-27 19:49:15.000000000 -0700
+++ libfind2.c	2014-06-27 19:50:30.000000000 -0700
@@ -83,7 +83,7 @@
            argv[2][i-2] == '1' && 
            argv[2][i-1] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
@@ -140,7 +140,7 @@
            argv[2][i-6] == '1' && 
            argv[2][i-5] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
@@ -211,7 +211,7 @@
            argv[2][i-2] == '1' && 
            argv[2][i-1] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
@@ -257,7 +257,7 @@
            argv[2][i-2] == '1' && 
            argv[2][i-1] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
