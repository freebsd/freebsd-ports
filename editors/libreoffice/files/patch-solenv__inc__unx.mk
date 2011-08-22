--- solenv/inc/unx.mk.orig	2011-07-23 08:18:24.000000000 +0300
+++ solenv/inc/unx.mk	2011-07-23 08:20:06.000000000 +0300
@@ -139,8 +139,12 @@
 .INCLUDE : unxbsds.mk
 .ENDIF
 
-.IF "$(COM)$(OS)" == "GCCFREEBSD"
-.INCLUDE : unxfbsd.mk
+.IF "$(COM)$(OS)$(CPU)" == "GCCFREEBSDI"
+.INCLUDE : unxfbsdi.mk
+.ENDIF
+
+.IF "$(COM)$(OS)$(CPU)" == "GCCFREEBSDX"
+.INCLUDE : unxfbsdx.mk
 .ENDIF
 
 .IF "$(COM)$(OS)" == "GCCOPENBSD"
