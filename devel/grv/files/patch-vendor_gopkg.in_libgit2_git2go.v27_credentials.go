--- vendor/gopkg.in/libgit2/git2go.v27/credentials.go.orig	2019-01-04 13:40:18 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/credentials.go
@@ -2,6 +2,9 @@ package git
 
 /*
 #include <git2.h>
+#include <git2/sys/cred.h>
+
+git_credtype_t _go_git_cred_credtype(git_cred *cred);
 */
 import "C"
 import "unsafe"
@@ -27,7 +30,7 @@ func (o *Cred) HasUsername() bool {
 }
 
 func (o *Cred) Type() CredType {
-	return (CredType)(o.ptr.credtype)
+	return (CredType)(C._go_git_cred_credtype(o.ptr))
 }
 
 func credFromC(ptr *C.git_cred) *Cred {
