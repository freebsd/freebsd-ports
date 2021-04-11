--- unix/config/ax_check_openexr.m4.orig	2018-05-27 09:54:06 UTC
+++ unix/config/ax_check_openexr.m4
@@ -56,7 +56,7 @@ AC_DEFUN([AX_CHECK_OPENEXR],
       # check include file
       AC_CHECK_HEADER(
         [OpenEXR/ImfCRgbaFile.h],
-        [AC_CHECK_LIB([IlmImf], [ImfInputReadPixels], [], [ax_check_openexr="not found"])],
+        [AC_CHECK_LIB([OpenEXR], [ImfInputReadPixels], [], [ax_check_openexr="not found"])],
         [ax_check_openexr="no headers"]
       )
     fi
