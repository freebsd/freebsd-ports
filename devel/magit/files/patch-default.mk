--- default.mk.orig	2017-06-14 12:34:54 UTC
+++ default.mk
@@ -85,14 +85,6 @@ ELGS = magit-autoloads.el magit-version.
 
 ## Versions ##########################################################
 
-VERSION := $(shell \
-  test -e $(TOP).git\
-  && git describe --tags --dirty 2> /dev/null\
-  || $(BATCH) --eval "(progn\
-  (fset 'message (lambda (&rest _)))\
-  (load-file \"magit-version.el\")\
-  (princ magit-version))")
-
 MAGIT_VERSION       = 2.10
 ASYNC_VERSION       = 1.9
 DASH_VERSION        = 2.13.0
