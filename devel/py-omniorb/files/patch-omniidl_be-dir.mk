--- omniidl_be/dir.mk.orig	Wed Feb  8 23:42:52 2006
+++ omniidl_be/dir.mk	Wed Feb  8 23:43:03 2006
@@ -13,8 +13,6 @@
           for file in $^; do \
             $(ExportFileToDir) \
           done; \
-          cd $(PYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
 	 )
 
 ifdef INSTALLTARGET
@@ -23,7 +21,5 @@
           for file in $^; do \
             $(ExportFileToDir) \
           done; \
-          cd $(INSTALLPYLIBDIR); \
-	  $(PYTHON) -c "import compileall; compileall.compile_dir('.')"; \
 	 )
 endif
