--- ../stoc/source/javavm/makefile.mk.orig	Fri Dec  6 11:48:59 2002
+++ ../stoc/source/javavm/makefile.mk	Wed Mar  5 19:36:03 2003
@@ -100,10 +100,10 @@
 SHL1TARGET= $(TARGET)
 SHL1VERSIONMAP=$(TARGET).map
 SHL1STDLIBS= \
+		$(SALLIB) \
 		$(CPPUHELPERLIB) 	\
 		$(CPPULIB)	    	\
 		$(UNOLIB)	    	\
-		$(SALLIB) \
         $(JVMACCESSLIB) \
         $(SALHELPERLIB)
 
