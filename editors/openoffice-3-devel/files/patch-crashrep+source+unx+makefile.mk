--- ../crashrep/source/unx/makefile.mk.orig	Tue Jul 22 19:37:38 2003
+++ ../crashrep/source/unx/makefile.mk	Thu Aug 14 18:44:09 2003
@@ -123,7 +123,7 @@
 APP2STDLIBS+=-lsocket
 .ENDIF
 .IF "$(OS)" == "FREEBSD"
-APP2STDLIBS=$(STATIC) `pkg-config --libs gtk+-2.0` -lpng -lzlib -ljpeg -ltiff $(DYNAMIC) -lXext -lX11
+APP2STDLIBS=$(STATIC) `pkg-config --libs gtk+-2.0` -lpng -lzlib -ljpeg -ltiff -lintl -lfreetype -lexpat $(DYNAMIC) -lXext -lX11
 .ENDIF
 
 .ENDIF
