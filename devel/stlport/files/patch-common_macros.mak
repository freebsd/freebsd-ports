--- src/common_macros.mak.orig	Sat Jul 28 23:44:30 2001
+++ src/common_macros.mak	Fri Oct  5 09:05:56 2001
@@ -14,7 +14,7 @@
 # We do not assume any binary compatibility for betas.
 BETA_SUFFIX=
 
-VERSION_SUFFIX= .$(VERSION_MAJOR).$(VERSION_MINOR)$(BETA_SUFFIX)
+VERSION_SUFFIX= _$(VERSION_MAJOR)_$(VERSION_MINOR)$(BETA_SUFFIX)
 
 DYNAMIC_SUFFIX= $(VERSION_SUFFIX)$(PATCH_SUFFIX)
 
