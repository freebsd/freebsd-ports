--- ../cpputools/source/registercomponent/makefile.mk.orig	Mon Apr 22 22:46:11 2002
+++ ../cpputools/source/registercomponent/makefile.mk	Mon Apr 22 22:46:44 2002
@@ -104,6 +104,7 @@
 
 APP1STDLIBS=\
 			$(SALLIB) \
+			$(TOOLSLIB) \
 			$(CPPULIB)	\
 			$(CPPUHELPERLIB)
 
