--- vendor/gopkg.in/libgit2/git2go.v27/odb.go.orig	2019-01-04 13:40:18 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/odb.go
@@ -210,7 +210,7 @@ func (v *Odb) NewWriteStream(size int64, otype ObjectT
 	runtime.LockOSThread()
 	defer runtime.UnlockOSThread()
 
-	ret := C.git_odb_open_wstream(&stream.ptr, v.ptr, C.git_off_t(size), C.git_otype(otype))
+	ret := C.git_odb_open_wstream(&stream.ptr, v.ptr, C.git_object_size_t(size), C.git_object_t(otype))
 	runtime.KeepAlive(v)
 	if ret < 0 {
 		return nil, MakeGitError(ret)
