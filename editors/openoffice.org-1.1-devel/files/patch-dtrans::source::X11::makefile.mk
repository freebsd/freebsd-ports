--- ../dtrans/source/X11/makefile.mk.orig	Tue Dec 11 18:48:36 2001
+++ ../dtrans/source/X11/makefile.mk	Wed Apr  3 00:31:56 2002
@@ -116,7 +116,8 @@
 APP1STDLIBS=\
 		$(CPPULIB)			\
 		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(SALLIB) \
+		-lX11
 
 .ENDIF		# "$(OS)"=="MACOSX"
 
