--- ../stlport/makefile.mk.orig	Tue Aug 27 19:26:10 2002
+++ ../stlport/makefile.mk	Fri Oct 18 22:33:22 2002
@@ -107,16 +107,26 @@
 
 .IF "$(COM)"=="GCC"
 .IF "$(COMID)"=="gcc3"
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
 .ENDIF
 
 .IF "$(COM)"=="C52"
