--- ../stoc/source/loader/makefile.mk.orig	Tue Jan  1 14:12:02 2002
+++ ../stoc/source/loader/makefile.mk
@@ -83,9 +83,9 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1VERSIONMAP=$(TARGET).map
 SHL1DEPN=
