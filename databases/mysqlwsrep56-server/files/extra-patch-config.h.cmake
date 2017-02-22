--- config.h.cmake.orig	2014-12-05 16:24:02 UTC
+++ config.h.cmake
@@ -151,7 +151,8 @@
 #cmakedefine HAVE_FESETROUND 1
 #cmakedefine HAVE_FINITE 1
 #cmakedefine HAVE_FP_EXCEPT 1
-#cmakedefine HAVE_FPSETMASK 1
+#cmakedefine HAVE_FPSETMASK 0
+#cmakedefine HAVE_FEDISABLEEXCEPT 1
 #cmakedefine HAVE_FSEEKO 1
 #cmakedefine HAVE_FSYNC 1
 #cmakedefine HAVE_FTIME 1
