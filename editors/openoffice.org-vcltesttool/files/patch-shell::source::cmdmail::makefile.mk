--- ../shell/source/cmdmail/makefile.mk.orig	Tue Jan  1 14:11:38 2002
+++ ../shell/source/cmdmail/makefile.mk
@@ -81,9 +81,10 @@
 			
 SHL1TARGET=$(TARGET)
 
-SHL1STDLIBS=$(CPPULIB)\
-			$(CPPUHELPERLIB)\
-			$(SALLIB)
+SHL1STDLIBS=\
+			$(SALLIB)\
+			$(CPPULIB)\
+			$(CPPUHELPERLIB)
 
 SHL1LIBS=
 		
