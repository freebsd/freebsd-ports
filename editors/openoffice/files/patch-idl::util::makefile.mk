--- ../idl/util/makefile.mk.orig	Sun Jul 21 00:02:37 2002
+++ ../idl/util/makefile.mk	Sun Jul 21 00:02:39 2002
@@ -110,7 +110,7 @@
 .ENDIF
 .ENDIF
 
-.IF "$(OS)"=="LINUX"
+.IF "$(OS)"=="LINUX" || "$(OS)"=="FREEBSD"
 APP1STDLIBS+=-lcrypt
 .ENDIF
 
