Temporarily disable libgit2 version check in git2go until v0.28 tag is added.
Upstream issue: https://github.com/libgit2/git2go/issues/502
--- vendor/gopkg.in/libgit2/git2go.v27/git_dynamic.go.orig	2019-03-23 19:12:03 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/git_dynamic.go
@@ -6,9 +6,5 @@ package git
 #include <git2.h>
 #cgo pkg-config: libgit2
 
-#if LIBGIT2_VER_MAJOR != 0 || LIBGIT2_VER_MINOR != 27
-# error "Invalid libgit2 version; this git2go supports libgit2 v0.27"
-#endif
-
 */
 import "C"
