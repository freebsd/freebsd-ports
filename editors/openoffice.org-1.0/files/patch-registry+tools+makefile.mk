Index: registry/tools/makefile.mk
===================================================================
RCS file: /cvs/udk/registry/tools/makefile.mk,v
retrieving revision 1.4
diff -u -r1.4 makefile.mk
--- registry/tools/makefile.mk	18 May 2001 15:20:12 -0000	1.4
+++ registry/tools/makefile.mk	10 Jul 2005 05:16:53 -0000
@@ -88,6 +88,7 @@
 APP1STDLIBS=\
             $(SALLIB) \
             $(SALHELPERLIB) \
+            $(STORELIB) \
             $(REGLIB)
 
 .IF "$(GUI)"=="WNT"
@@ -102,6 +103,7 @@
 APP2STDLIBS=\
             $(SALLIB) \
             $(SALHELPERLIB) \
+            $(STORELIB) \
             $(REGLIB)
 
 .IF "$(GUI)"=="WNT"
@@ -115,6 +117,7 @@
 APP3STDLIBS=\
             $(SALLIB) \
             $(SALHELPERLIB) \
+            $(STORELIB) \
             $(REGLIB)
 
 .IF "$(GUI)"=="WNT"
@@ -128,6 +131,7 @@
 APP4STDLIBS=\
             $(SALLIB) \
             $(SALHELPERLIB) \
+            $(STORELIB) \
             $(REGLIB)
 
 .IF "$(GUI)"=="WNT"
