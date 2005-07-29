--- stlport/makefile.mk.orig	Tue Jan  7 13:13:37 2003
+++ stlport/makefile.mk	Sat Jan 18 13:01:53 2003
@@ -98,16 +98,28 @@
 
 .IF "$(COM)"=="GCC"
 .IF "$(COMID)"=="gcc3"
-BUILD_FLAGS=-f gcc-3.0.mak
+.IF # "$(OS)"=="FREEBSD"
+    BUILD_FLAGS=-f gcc-3.0-freebsd.mak
+.ELSE
+    BUILD_FLAGS=-f gcc-3.0.mak
+.ENDIF
 .ELSE # "$(COMID)"=="gcc3"
-# MacOS X/Darwin need a special makefile
+# FreeBSD / MacOS X/Darwin need a special makefile
 .IF "$(OS)"=="MACOSX"
     BUILD_FLAGS=-f gcc-apple-macosx.mak
-.ELSE # "$(OS)"=="MACOSX"
+.ELSIF # "$(OS)"=="FREEBSD"
+    BUILD_FLAGS=-f gcc-freebsd.mak
+.ELSE
     BUILD_FLAGS=-f gcc.mak
-.ENDIF # "$(OS)"=="MACOSX"
+.ENDIF # "$(OS)"=="MACOSX || $(OS)"=="FREEBSD"
 .ENDIF # "$(COMID)"=="gcc3"
-BUILD_ACTION=make
+
+.IF "$(OS)"=="FREEBSD"
+    BUILD_ACTION=gmake
+.ELSE
+    BUILD_ACTION=make
+.ENDIF
+
 # build in parallel
 BUILD_FLAGS+= -j$(MAXPROCESS)
 .ENDIF
