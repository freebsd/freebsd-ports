--- icu/makefile.mk.orig	2025-12-27 09:25:15 UTC
+++ icu/makefile.mk
@@ -44,6 +44,7 @@ PATCH_FILES=${TARFILE_NAME}.patch icu-win-layout.patch
 
 # TODO file icu-mp.patch does not seem to be required
 PATCH_FILES=${TARFILE_NAME}.patch icu-win-layout.patch \
+	icu-parallel-build.patch \
 	icu-format-security.patch icu-win-icutu-dll-version.patch
 .IF "$(OS)"=="MACOSX"
 PATCH_FILES+=icu-darwin.patch
