--- python3/dir.mk.orig	2022-01-18 19:50:00 UTC
+++ python3/dir.mk
@@ -24,7 +24,7 @@ export:: $(FILES)
             $(ExportFileToDir) \
           done; \
           cd $(PYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
+	  $(PYTHON) -c "import compileall; compileall.compile_dir('.',0)"; \
 	 )
 
 ifdef INSTALLTARGET
@@ -34,6 +34,6 @@ install:: $(FILES)
             $(ExportFileToDir) \
           done; \
           cd $(INSTALLPYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
+	  $(PYTHON) -c "import compileall; compileall.compile_dir('.',0)"; \
 	 )
 endif
