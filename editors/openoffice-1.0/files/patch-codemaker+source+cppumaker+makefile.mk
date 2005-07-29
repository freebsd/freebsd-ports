Index: codemaker/source/cppumaker/makefile.mk
===================================================================
RCS file: /cvs/udk/codemaker/source/cppumaker/makefile.mk,v
retrieving revision 1.5
diff -u -r1.5 makefile.mk
--- codemaker/source/cppumaker/makefile.mk	17 Aug 2001 13:15:48 -0000	1.5
+++ codemaker/source/cppumaker/makefile.mk	10 Jul 2005 07:39:54 -0000
@@ -92,6 +92,7 @@
 APP1STDLIBS= \
              $(SALLIB) \
              $(SALHELPERLIB) \
+             $(STORELIB) \
              $(REGLIB) 
 
 APP1LIBS= \
