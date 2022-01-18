--- python3/omniidl_be/dir.mk.orig	2022-01-18 19:52:54 UTC
+++ python3/omniidl_be/dir.mk
@@ -13,8 +13,6 @@ export:: $(FILES)
           for file in $^; do \
             $(ExportFileToDir) \
           done; \
-          cd $(PYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
 	 )
 
 ifdef INSTALLTARGET
@@ -23,7 +21,5 @@ install:: $(FILES)
           for file in $^; do \
             $(ExportFileToDir) \
           done; \
-          cd $(INSTALLPYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
 	 )
 endif
