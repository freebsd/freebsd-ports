--- ../psprint/util/makefile.mk.orig	Sat Mar  2 22:24:38 2002
+++ ../psprint/util/makefile.mk	Sat Mar  2 22:25:27 2002
@@ -91,7 +91,9 @@
 .IF "$(OS)"=="SOLARIS"
 SHL1VERSIONMAP=libpsp_solaris.map
 .ELSE   # should work for all gcc/binutils based linker (ld)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=libpsp_linux.map
+.ENDIF
 .ENDIF
 SHL1STDLIBS=$(UNOTOOLSLIB)		\
 			$(TOOLSLIB) 		\
