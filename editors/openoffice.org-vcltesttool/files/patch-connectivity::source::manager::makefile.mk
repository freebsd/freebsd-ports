--- ../connectivity/source/manager/makefile.mk.orig	Tue Jan  1 14:09:00 2002
+++ ../connectivity/source/manager/makefile.mk
@@ -92,11 +92,11 @@
 .ENDIF
 SHL1OBJS=$(SLOFILES)
 SHL1STDLIBS=\
+	$(SALLIB)					\
 	$(CPPULIB)					\
 	$(CPPUHELPERLIB)			\
 	$(VOSLIB)					\
-	$(OSLLIB)					\
-	$(SALLIB)
+	$(OSLLIB)					
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(SHL1TARGET)
