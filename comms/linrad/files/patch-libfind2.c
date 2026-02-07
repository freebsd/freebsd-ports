--- libfind2.c.orig	2014-11-04 10:25:00 UTC
+++ libfind2.c
@@ -83,7 +83,7 @@ findlinux:;
            argv[2][i-2] == '1' && 
            argv[2][i-1] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
@@ -140,7 +140,7 @@ findlinux:;
            argv[2][i-6] == '1' && 
            argv[2][i-5] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
@@ -211,7 +211,7 @@ findmac:;
            argv[2][i-2] == '1' && 
            argv[2][i-1] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
@@ -257,7 +257,7 @@ findmac:;
            argv[2][i-2] == '1' && 
            argv[2][i-1] == '1')
           {
-          sprintf(&argv[2][j],"include/X11");
+          sprintf(&argv[2][j],"include");
           }
         else  
           {
