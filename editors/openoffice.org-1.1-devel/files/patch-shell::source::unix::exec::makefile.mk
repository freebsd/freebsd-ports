--- ../shell/source/unix/exec/makefile.mk.orig	Tue Jan  1 14:11:38 2002
+++ ../shell/source/unix/exec/makefile.mk
@@ -79,9 +79,10 @@
 						
 SHL1TARGET=$(TARGET)
 
-SHL1STDLIBS=$(CPPULIB)\
-			$(CPPUHELPERLIB)\
-			$(SALLIB)
+SHL1STDLIBS=\
+			$(SALLIB)\
+			$(CPPULIB)\
+			$(CPPUHELPERLIB)
 
 SHL1LIBS=
 		
