--- src/pymod/tl/tl.pro.orig	2022-12-22 22:17:08 UTC
+++ src/pymod/tl/tl.pro
@@ -33,14 +33,14 @@ msvc {
 }
 
 # INSTALLS needs to be inside a lib or app templates.
-init_target.path = $$PREFIX/pymod/klayout
+init_target.path = $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout)
 # This would be nice:
 #   init_target.files += $$DESTDIR_PYMOD/__init__.py
 # but some Qt versions need this explicitly:
 msvc {
   init_target.extra = $(INSTALL_PROGRAM) $$shell_path($$DESTDIR_PYMOD/__init__.py) $$shell_path($(INSTALLROOT)$$PREFIX/pymod/klayout)
 } else {
-  init_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/__init__.py $(INSTALLROOT)$$PREFIX/pymod/klayout
+  init_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/__init__.py $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout)
 }
 INSTALLS += init_target
 
@@ -53,13 +53,13 @@ msvc {
 }
 
 # INSTALLS needs to be inside a lib or app templates.
-modpyasrc_target.path = $$PREFIX/pymod/pya
+modpyasrc_target.path = $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout/pya)
 # This would be nice:
 #   init_target.files += $$DESTDIR_PYMOD/pya/*
 # but some Qt versions need this explicitly:
 msvc {
   modpyasrc_target.extra = $(INSTALL_PROGRAM) $$shell_path($$DESTDIR_PYMOD/../pya/*.py) $$shell_path($(INSTALLROOT)$$PREFIX/pymod/pya)
 } else {
-  modpyasrc_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/../pya/*.py $(INSTALLROOT)$$PREFIX/pymod/pya
+  modpyasrc_target.extra = $(INSTALL_PROGRAM) $$DESTDIR_PYMOD/../pya/*.py $$shell_path($(INSTALLROOT)$(PYTHON_SITELIBDIR)/klayout/pya)
 }
 INSTALLS += modpyasrc_target
