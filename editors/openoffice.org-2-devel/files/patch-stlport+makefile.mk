--- ../stlport/makefile.mk.orig	Thu Feb 20 16:13:40 2003
+++ ../stlport/makefile.mk	Wed Mar  5 19:41:42 2003
@@ -104,16 +104,27 @@
 
 .IF "$(COM)"=="GCC"
 .IF "$(COMID)"=="gcc3"
+# FreeBSD needs a special makefile
+.IF "$(OS)"=="FREEBSD"
+BUILD_FLAGS=-f gcc-3.0-freebsd.mak
+.ELSE
 BUILD_FLAGS=-f gcc-3.0.mak
+.ENDIF
 .ELSE # "$(COMID)"=="gcc3"
 # MacOS X/Darwin need a special makefile
 .IF "$(OS)"=="MACOSX"
     BUILD_FLAGS=-f gcc-apple-macosx.mak
+.ELIF "$(OS)"=="FREEBSD"
+    BUILD_FLAGS=-f gcc-freebsd.mak
 .ELSE # "$(OS)"=="MACOSX"
     BUILD_FLAGS=-f gcc.mak
 .ENDIF # "$(OS)"=="MACOSX"
 .ENDIF # "$(COMID)"=="gcc3"
+.IF "$(OS)"=="FREEBSD"
+BUILD_ACTION=gmake
+.ELSE
 BUILD_ACTION=make
+.ENDIF
 # build in parallel
 BUILD_FLAGS+= -j$(MAXPROCESS)
 .ENDIF
