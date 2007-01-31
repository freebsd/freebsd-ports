--- libltdl/acinclude.m4.orig	Sun Dec 18 14:13:49 2005
+++ libltdl/acinclude.m4	Tue Jan 30 17:30:22 2007
@@ -6526,2 +6526,5 @@
     ;;
+  freebsd*)
+    libltdl_cv_sys_dlopen_deplibs=yes
+    ;;
   gnu* | linux* | kfreebsd*-gnu | knetbsd*-gnu)
