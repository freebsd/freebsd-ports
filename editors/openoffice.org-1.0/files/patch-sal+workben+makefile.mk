--- ../sal/workben/makefile.mk.orig	Sun Mar  3 01:27:32 2002
+++ ../sal/workben/makefile.mk	Sun Mar  3 01:27:54 2002
@@ -325,7 +325,7 @@
 # tgetpwnam
 #
 .IF "$(TESTAPP)" == "tgetpwnam"
-.IF "$(OS)"=="SCO" || "$(OS)"=="NETBSD"
+.IF "$(OS)"=="SCO" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 
 CXXFILES=	tgetpwnam.cxx
 OBJFILES=	$(OBJ)$/tgetpwnam.obj
@@ -335,7 +335,7 @@
 APP5STDLIBS=$(SALLIB)
 APP5DEPN=	$(SLB)$/sal.lib
 
-.ENDIF # (sco | netbsd)
+.ENDIF # (sco | netbsd || freebsd)
 .ENDIF # tgetpwname
 
 # --- Targets ------------------------------------------------------
