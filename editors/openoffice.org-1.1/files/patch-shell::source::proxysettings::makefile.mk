--- ../shell/source/proxysettings/makefile.mk.orig	Tue Jan  1 14:11:38 2002
+++ ../shell/source/proxysettings/makefile.mk
@@ -85,9 +85,10 @@
 
 SHL1TARGET=$(TARGET)
 
-SHL1STDLIBS=$(CPPULIB)\
-			$(CPPUHELPERLIB)\
-			$(SALLIB)
+SHL1STDLIBS=\
+			$(SALLIB)\
+			$(CPPULIB)\
+			$(CPPUHELPERLIB)
 
 SHL1LIBS=
 		
