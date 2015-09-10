--- default.mk.orig	2015-07-18 04:15:03 UTC
+++ default.mk
@@ -71,11 +71,3 @@ EMACSOLD := $(shell $(BATCH) --eval \
 ifeq "$(EMACSOLD)" "true"
   $(error At least version 24.4 of Emacs is required)
 endif
-
-VERSION := $(shell \
-  test -e $(TOP).git\
-  && git describe --tags --dirty 2> /dev/null\
-  || $(BATCH) --eval "(progn\
-  (fset 'message (lambda (&rest _)))\
-  (load-file \"magit-version.el\")\
-  (princ magit-version))")
