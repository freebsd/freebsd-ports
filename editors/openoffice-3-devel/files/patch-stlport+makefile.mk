--- ../stlport/makefile.mk.orig	Tue Mar 19 15:49:17 2002
+++ ../stlport/makefile.mk	Tue May 28 23:03:45 2002
@@ -106,11 +106,29 @@
 
 .IF "$(COM)"=="GCC"
 .IF "$(COMID)"=="gcc3"
+
+.IF "$(OS)"=="FREEBSD"
+BUILD_FLAGS=-f gcc-3.0-freebsd.mak
+.ELSE
 BUILD_FLAGS=-f gcc-3.0.mak
+.ENDIF
+
 .ELSE # "$(COMID)"=="gcc3"
+
+.IF "$(OS)"=="FREEBSD"
+BUILD_FLAGS=-f gcc-freebsd.mak
+.ELSE
 BUILD_FLAGS=-f gcc.mak
+.ENDIF
+
 .ENDIF # "$(COMID)"=="gcc3"
+
+.IF "$(OS)"=="FREEBSD"
+BUILD_ACTION=gmake
+.ELSE
 BUILD_ACTION=make
+.ENDIF
+
 .ENDIF
 
 .IF "$(COM)"=="C52"
