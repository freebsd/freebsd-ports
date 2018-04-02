--- default.mk.orig	2018-03-29 20:07:19 UTC
+++ default.mk
@@ -89,8 +89,6 @@ ELGS = magit-autoloads.el magit-version.
 
 ## Versions ##########################################################
 
-VERSION ?= $(shell test -e $(TOP).git && git describe --tags --abbrev=0)
-
 ASYNC_VERSION       = 1.9.2
 DASH_VERSION        = 2.13.0
 GHUB_VERSION        = 2.0.0
