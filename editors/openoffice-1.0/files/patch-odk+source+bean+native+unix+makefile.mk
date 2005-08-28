Index: odk/source/bean/native/unix/makefile.mk
===================================================================
RCS file: /cvs/api/odk/source/bean/native/unix/Attic/makefile.mk,v
retrieving revision 1.4
diff -u -r1.4 makefile.mk
--- odk/source/bean/native/unix/makefile.mk	6 May 2002 18:56:38 -0000	1.4
+++ odk/source/bean/native/unix/makefile.mk	3 Aug 2005 07:10:36 -0000
@@ -20,9 +20,12 @@
 SHL1LIBS=	$(SLB)$/$(TARGET).lib
 SHL1STDLIBS=-ljawt -lsal
 
-.IF "$(OS)" == "LINUX"
+.IF "$(OS)" == "LINUX" || "$(OS)" == "FREEBSD"
 SHL1STDLIBS+=-lstdc++
 .ENDIF
+.IF "$(OS)" == "FREEBSD"
+SHL1STDLIBS+=-ljvm -lhpi
+.ENDIF
 
 NO_SHL1DESCRIPTION=TRUE
 
