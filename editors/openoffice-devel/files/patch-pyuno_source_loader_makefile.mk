--- pyuno/source/loader/makefile.mk.orig	2019-09-17 22:55:18 UTC
+++ pyuno/source/loader/makefile.mk
@@ -41,7 +41,7 @@ PYTHONLIB=$(PYTHON_LIBS)
 
 .IF "$(SYSTEM_PYTHON)" == "YES"
 PYTHONLIB=$(PYTHON_LIBS)
-CFLAGS+=$(PYTHON_CFLAGS)
+INCSYSTEM+=$(PYTHON_CFLAGS)
 .IF "$(EXTRA_CFLAGS)"!=""
 PYTHONLIB+=-framework Python
 .ENDIF # "$(EXTRA_CFLAGS)"!=""
