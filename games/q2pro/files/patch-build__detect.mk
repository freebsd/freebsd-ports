--- ./build/detect.mk.orig	Mon Dec 25 17:07:02 2006
+++ ./build/detect.mk	Mon Dec 25 17:07:02 2006
@@ -21,7 +21,7 @@
 ifeq (linux,$(TARGETOS))
 EXEEXT = #blank
 SHLIBEXT = .so
-OUTDIRSUFFIX = i386
+OUTDIRSUFFIX = #blank
 else
 $(error Unknown target OS)
 endif
