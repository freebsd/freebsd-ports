--- ../sal/workben/makefile.mk.orig	Tue Apr  8 17:54:30 2003
+++ ../sal/workben/makefile.mk	Sat May 31 23:35:21 2003
@@ -167,7 +167,7 @@
 
 .IF "$(TESTAPP)" == "salstattest"
 
-	CFLAGS+= /DUSE_SAL_STATIC
+	CFLAGS+= -DUSE_SAL_STATIC
 
 	OBJFILES=	$(OBJ)$/salstattest.obj
 
@@ -379,7 +379,7 @@
 # tgetpwnam
 #
 .IF "$(TESTAPP)" == "tgetpwnam"
-.IF "$(OS)"=="SCO" || "$(OS)"=="NETBSD"
+.IF "$(OS)"=="SCO" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
 
 CXXFILES=	tgetpwnam.cxx
 OBJFILES=	$(OBJ)$/tgetpwnam.obj
@@ -389,7 +389,7 @@
 APP5STDLIBS=$(SALLIB)
 APP5DEPN=	$(SLB)$/sal.lib
 
-.ENDIF # (sco | netbsd)
+.ENDIF # (sco | netbsd | freebsd)
 .ENDIF # tgetpwname
 
 # --- Targets ------------------------------------------------------
