--- stoc/source/tdmanager/makefile.mk.orig	Tue Jan  1 14:12:03 2002
+++ stoc/source/tdmanager/makefile.mk
@@ -83,9 +83,10 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
+
 SHL1VERSIONMAP=$(TARGET).map
 
 SHL1DEPN=
