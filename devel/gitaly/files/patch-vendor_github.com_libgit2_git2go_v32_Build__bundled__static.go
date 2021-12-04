--- vendor/github.com/libgit2/git2go/v32/Build_bundled_static.go.orig	2021-11-22 21:32:43 UTC
+++ vendor/github.com/libgit2/git2go/v32/Build_bundled_static.go
@@ -10,7 +10,7 @@ package git
 #cgo CFLAGS: -DLIBGIT2_STATIC
 #include <git2.h>
 
-#if LIBGIT2_VER_MAJOR != 1 || LIBGIT2_VER_MINOR < 2 || LIBGIT2_VER_MINOR > 2
+#if LIBGIT2_VER_MAJOR != 1 || LIBGIT2_VER_MINOR < 2 || LIBGIT2_VER_MINOR > 3
 # error "Invalid libgit2 version; this git2go supports libgit2 between v1.2.0 and v1.2.0"
 #endif
 */
