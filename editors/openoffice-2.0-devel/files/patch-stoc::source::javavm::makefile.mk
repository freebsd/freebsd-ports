--- ../stoc/source/javavm/makefile.mk.orig	Tue Jan  1 14:12:02 2002
+++ ../stoc/source/javavm/makefile.mk
@@ -91,10 +91,10 @@
 SHL1TARGET= $(TARGET)
 SHL1VERSIONMAP=$(TARGET).map
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPUHELPERLIB) 	\
 		$(CPPULIB)	    	\
-		$(UNOLIB)	    	\
-		$(SALLIB)
+		$(UNOLIB)
 
 .IF "$(GUI)"=="WNT"
 SHL1STDLIBS += advapi32.lib
