--- default.mk.orig	2018-06-03 00:38:37 UTC
+++ default.mk
@@ -89,8 +89,6 @@ ELGS = magit-autoloads.el magit-version.
 
 ## Versions ##########################################################
 
-VERSION ?= $(shell test -e $(TOP).git && git describe --tags --abbrev=0)
-
 ASYNC_VERSION       = 1.9.3
 DASH_VERSION        = 2.14.1
 GHUB_VERSION        = 2.0.1
