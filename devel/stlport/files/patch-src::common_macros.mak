--- src/common_macros.mak.orig	Sun Nov  2 16:58:51 2003
+++ src/common_macros.mak	Sun Oct 31 17:02:57 2004
@@ -10,7 +10,7 @@
 # We do not assume any binary compatibility for betas.
 BETA_SUFFIX=
 
-VERSION_SUFFIX= .$(VERSION_MAJOR).$(VERSION_MINOR)$(BETA_SUFFIX)
+VERSION_SUFFIX= _$(VERSION_MAJOR)_$(VERSION_MINOR)$(BETA_SUFFIX)
 WIN_VERSION_SUFFIX= $(VERSION_MAJOR)$(VERSION_MINOR)$(BETA_SUFFIX)
 
 # DYNAMIC_SUFFIX= $(VERSION_SUFFIX)$(PATCH_SUFFIX)
