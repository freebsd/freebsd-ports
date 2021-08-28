--- src/pymod/pymod.pri.orig	2021-07-23 08:00:26 UTC
+++ src/pymod/pymod.pri
@@ -9,7 +9,7 @@ include($$PWD/../klayout.pri)
 
 INCLUDEPATH += "$$PYTHONINCLUDE" $$TL_INC $$GSI_INC $$PYA_INC
 DEPENDPATH += "$$PYTHONINCLUDE" $$TL_INC $$GSI_INC $$PYA_INC
-LIBS += "$$PYTHONLIBFILE" -L$$LIBDIR -lklayout_tl -lklayout_gsi -lklayout_pya
+LIBS += "$$PYTHONLIBFILE" $$LIBDIR/libklayout_tl.so $$LIBDIR/libklayout_gsi.so $$LIBDIR/libklayout_pya.so
 
 !msvc {
   # Python is somewhat sloppy and relies on the compiler initializing fields
@@ -38,14 +38,14 @@ win32 {
 
 }
 
-lib_target.path = $$PREFIX/pymod/klayout
+lib_target.path = $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout)
 # This would be nice:
 #   lib_target.files += $$DESTDIR_PYMOD/$${TARGET}$${PYTHONEXTSUFFIX}
 # but some Qt versions need this explicitly:
 msvc {
   lib_target.extra = $(INSTALL_PROGRAM) $$shell_path($$DESTDIR_PYMOD/$${TARGET}$${PYTHONEXTSUFFIX}) $$shell_path($(INSTALLROOT)$$PREFIX/pymod/klayout)
 } else {
-  lib_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/$${TARGET}$${PYTHONEXTSUFFIX} $(INSTALLROOT)$$PREFIX/pymod/klayout
+  lib_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/$${TARGET}$${PYTHONEXTSUFFIX} $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout)
 }
 INSTALLS = lib_target
 
@@ -58,14 +58,14 @@ INSTALLS = lib_target
   }
 
   # INSTALLS needs to be inside a lib or app templates.
-  modsrc_target.path = $$PREFIX/pymod/klayout/$$REALMODULE
+  modsrc_target.path = $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout/$$REALMODULE)
   # This would be nice:
   #   init_target.files += $$DESTDIR_PYMOD/$$REALMODULE/*
   # but some Qt versions need this explicitly:
   msvc {
     modsrc_target.extra = $(INSTALL_PROGRAM) $$shell_path($$DESTDIR_PYMOD/$$REALMODULE/*.py) $$shell_path($(INSTALLROOT)$$PREFIX/pymod/klayout/$$REALMODULE)
   } else {
-    modsrc_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/$$REALMODULE/*.py $(INSTALLROOT)$$PREFIX/pymod/klayout/$$REALMODULE
+    modsrc_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/$$REALMODULE/*.py $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout/$$REALMODULE)
   }
   INSTALLS += modsrc_target
 
