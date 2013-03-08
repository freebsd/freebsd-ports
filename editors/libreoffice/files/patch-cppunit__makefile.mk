--- ./cppunit/makefile.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./cppunit/makefile.mk	2013-02-18 18:38:29.000000000 -0500
@@ -46,6 +46,10 @@
 PATCH_FILES += disable-dynloading.patch
 .ENDIF
 
+.IF "$(OS)" == "FREEBSD"
+PATCH_FILES += freebsd.patch
+.ENDIF
+
 .IF "$(OS)" == "WNT"
 .IF "$(COM)" == "MSC"
 
