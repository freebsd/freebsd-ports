--- vendor/gopkg.in/libgit2/git2go.v27/diff.go.orig	2018-07-05 13:56:38 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/diff.go
@@ -14,7 +14,7 @@ import (
 	"unsafe"
 )
 
-type DiffFlag int
+type DiffFlag int64
 
 const (
 	DiffFlagBinary    DiffFlag = C.GIT_DIFF_FLAG_BINARY
@@ -405,7 +405,7 @@ func (diff *Diff) Patch(deltaIndex int) 
 	return newPatchFromC(patchPtr), nil
 }
 
-type DiffOptionsFlag int
+type DiffOptionsFlag int64
 
 const (
 	DiffNormal                 DiffOptionsFlag = C.GIT_DIFF_NORMAL
