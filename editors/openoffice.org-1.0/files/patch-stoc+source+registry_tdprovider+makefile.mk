--- stoc/source/registry_tdprovider/makefile.mk.orig	Tue Jan  1 14:12:02 2002
+++ stoc/source/registry_tdprovider/makefile.mk
@@ -88,10 +88,10 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS=	\
+		$(SALLIB)		\
 		$(CPPULIB)		\
 		$(CPPUHELPERLIB)	\
-		$(SALHELPERLIB) 	\
-		$(SALLIB)
+		$(SALHELPERLIB) 
 
 SHL1DEPN=
 SHL1VERSIONMAP=$(TARGET).map
