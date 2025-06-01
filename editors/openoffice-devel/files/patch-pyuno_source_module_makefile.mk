--- pyuno/source/module/makefile.mk.orig	2019-09-17 22:55:18 UTC
+++ pyuno/source/module/makefile.mk
@@ -60,7 +60,7 @@ PYTHONLIB=$(PYTHON_LIBS)
 
 .IF "$(SYSTEM_PYTHON)" == "YES"
 PYTHONLIB=$(PYTHON_LIBS)
-CFLAGS+=$(PYTHON_CFLAGS)
+INCSYSTEM+=$(PYTHON_CFLAGS)
 .ELSE # "$(SYSTEM_PYTHON)" == "YES"
 .INCLUDE :  pyversion.mk
 CFLAGS+=-I$(SOLARINCDIR)$/python
