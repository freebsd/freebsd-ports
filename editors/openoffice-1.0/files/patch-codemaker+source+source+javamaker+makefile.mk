Index: codemaker/source/javamaker/makefile.mk
===================================================================
RCS file: /cvs/udk/codemaker/source/javamaker/makefile.mk,v
retrieving revision 1.7
diff -u -r1.7 makefile.mk
--- codemaker/source/javamaker/makefile.mk	17 Aug 2001 13:15:48 -0000	1.7
+++ codemaker/source/javamaker/makefile.mk	10 Jul 2005 08:39:43 -0000
@@ -96,6 +96,7 @@
 APP1STDLIBS= \
              $(SALLIB) \
              $(SALHELPERLIB)	\
+             $(STORELIB) \
              $(REGLIB)
 
 APP1LIBS= \
