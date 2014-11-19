--- python/dir.mk.orig	Wed Feb  8 23:42:23 2006
+++ python/dir.mk	Wed Feb  8 23:42:44 2006
@@ -24,7 +24,7 @@
             $(ExportFileToDir) \
           done; \
           cd $(PYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
+	  $(PYTHON) -c "import compileall; compileall.compile_dir('.',0)"; \
 	 )
 
 ifdef INSTALLTARGET
@@ -34,6 +34,6 @@
             $(ExportFileToDir) \
           done; \
           cd $(INSTALLPYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
+	  $(PYTHON) -c "import compileall; compileall.compile_dir('.',0)"; \
 	 )
 endif
