--- stoc/source/javaloader/makefile.mk.orig	Tue Jan  1 14:12:02 2002
+++ stoc/source/javaloader/makefile.mk
@@ -83,9 +83,10 @@
 SHL1TARGET= $(TARGET)
 
 SHL1STDLIBS=\
+		$(SALLIB)		\
 		$(CPPUHELPERLIB) 	\
-		$(CPPULIB)			\
-		$(SALLIB)
+		$(CPPULIB)
+
 SHL1VERSIONMAP=$(TARGET).map
 SHL1DEPN=		
 SHL1IMPLIB=		i$(TARGET)
