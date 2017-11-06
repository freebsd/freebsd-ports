--- default.mk.orig	2017-09-13 10:42:03 UTC
+++ default.mk
@@ -87,14 +87,6 @@ ELGS = magit-autoloads.el magit-version.
 
 ## Versions ##########################################################
 
-VERSION := $(shell \
-  test -e $(TOP).git\
-  && git describe --tags --dirty 2> /dev/null\
-  || $(BATCH) --eval "(progn\
-  (fset 'message (lambda (&rest _)))\
-  (load-file \"magit-version.el\")\
-  (princ magit-version))")
-
 MAGIT_VERSION       = 2.11
 ASYNC_VERSION       = 1.9.2
 DASH_VERSION        = 2.13.0
