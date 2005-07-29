--- setup2/patch/makefile.mk.orig	Sun Jul 21 00:21:46 2002
+++ setup2/patch/makefile.mk	Sun Jul 21 00:21:52 2002
@@ -92,7 +92,7 @@
 .IF "$(OS)"=="SOLARIS"
 	STATIC_LIBS+= -Bdynamic -lnsl -lsocket -lposix4
 .ENDIF
-.IF "$(OS)"=="LINUX"
+.IF "$(OS)"=="LINUX" || "$(OS)"=="FREEBSD"
 	STATIC_LIBS+= -Bdynamic -lcrypt
 .ENDIF
 .ELSE
