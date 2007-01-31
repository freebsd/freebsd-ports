--- ltdl.m4.orig	Sun Dec 18 13:53:17 2005
+++ ltdl.m4	Tue Jan 30 17:32:06 2007
@@ -129,2 +129,5 @@
     ;;
+  freebsd*)
+    libltdl_cv_sys_dlopen_deplibs=yes
+    ;;
   gnu* | linux* | kfreebsd*-gnu | knetbsd*-gnu)
