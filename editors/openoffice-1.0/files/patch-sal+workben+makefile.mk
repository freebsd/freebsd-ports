--- sal/workben/makefile.mk.orig	Tue May 15 14:11:20 2001
+++ sal/workben/makefile.mk	Sun Mar 10 23:46:59 2002
@@ -113,7 +113,7 @@
 
 .IF "$(TESTAPP)" == "salstattest"
 
-	CFLAGS+= /DUSE_SAL_STATIC
+	CFLAGS+= -DUSE_SAL_STATIC
 
 	OBJFILES=	$(OBJ)$/salstattest.obj
 
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
+.ENDIF # (sco | netbsd | freebsd)
 .ENDIF # tgetpwname
 
 # --- Targets ------------------------------------------------------
