--- ../dtrans/source/X11/makefile.mk.orig	Sat Mar  2 21:11:32 2002
+++ ../dtrans/source/X11/makefile.mk	Sat Mar  2 21:12:34 2002
@@ -111,7 +111,8 @@
 APP1STDLIBS=\
 		$(CPPULIB)			\
 		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(SALLIB) \
+		-lX11
 
 .ENDIF		# "$(OS)"=="MACOSX"
 
