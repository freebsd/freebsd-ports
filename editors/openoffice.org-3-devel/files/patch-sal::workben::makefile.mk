--- ../sal/workben/makefile.mk.orig	Tue Mar  5 21:38:42 2002
+++ ../sal/workben/makefile.mk	Tue Mar  5 21:39:11 2002
@@ -113,7 +113,7 @@
 
 .IF "$(TESTAPP)" == "salstattest"
 
-	CFLAGS+= /DUSE_SAL_STATIC
+	CFLAGS+= -DUSE_SAL_STATIC
 
 	OBJFILES=	$(OBJ)$/salstattest.obj
 
