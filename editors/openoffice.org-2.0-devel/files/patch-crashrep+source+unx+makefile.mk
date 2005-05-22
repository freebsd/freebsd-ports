Issutracker : #i49679#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : We don't have -ldl and -lnsl

Index: crashrep/source/unx/makefile.mk
===================================================================
RCS file: /cvs/porting/crashrep/source/unx/makefile.mk,v
retrieving revision 1.14
diff -u -r1.14 makefile.mk
--- crashrep/source/unx/makefile.mk	8 Mar 2005 16:24:14 -0000	1.14
+++ crashrep/source/unx/makefile.mk	28 Mar 2005 08:11:57 -0000
@@ -82,7 +82,10 @@
 APP1TARGET=$(TARGET)
 APP1OBJS=$(OBJFILES)
 
-APP1STDLIBS=$(DYNAMIC) -lXext -lX11 -ldl -lnsl
+APP1STDLIBS=$(DYNAMIC) -lXext -lX11
+.IF "$(OS)" != "FREEBSD"
+APP1STDLIBS+=-ldl -lnsl
+.ENDIF
 .IF "$(OS)" == "SOLARIS"
 APP1STDLIBS+=-lsocket
 .ENDIF
