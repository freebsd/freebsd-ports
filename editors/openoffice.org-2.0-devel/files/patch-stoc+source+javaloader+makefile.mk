--- ../stoc/source/javaloader/makefile.mk.orig	Fri Dec  6 11:51:54 2002
+++ ../stoc/source/javaloader/makefile.mk	Wed Mar  5 19:35:11 2003
@@ -83,10 +83,10 @@
 SHL1TARGET= $(TARGET)
 
 SHL1STDLIBS=\
+		$(SALLIB) \
 		$(CPPUHELPERLIB) 	\
 		$(CPPULIB)			\
-		$(SALLIB) \
-        $(JVMACCESSLIB)
+		$(JVMACCESSLIB)
 
 SHL1VERSIONMAP=$(TARGET).map
 SHL1DEPN=		
