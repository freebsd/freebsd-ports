--- ../javaunohelper/source/makefile.mk.orig	Thu Feb 20 17:28:43 2003
+++ ../javaunohelper/source/makefile.mk	Wed Mar  5 21:04:09 2003
@@ -118,9 +118,9 @@
 SHL1TARGET=juhx
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(JVMACCESSLIB)		\
 		$(SALHELPERLIB)		\
-		$(SALLIB)		\
 		$(CPPULIB)		\
 		$(CPPUHELPERLIB)
 
