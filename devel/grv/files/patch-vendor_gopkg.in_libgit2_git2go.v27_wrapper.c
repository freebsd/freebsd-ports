--- vendor/gopkg.in/libgit2/git2go.v27/wrapper.c.orig	2020-03-13 07:17:07 UTC
+++ vendor/gopkg.in/libgit2/git2go.v27/wrapper.c
@@ -2,6 +2,7 @@
 #include <git2.h>
 #include <git2/sys/odb_backend.h>
 #include <git2/sys/refdb_backend.h>
+#include <git2/sys/cred.h>
 
 typedef int (*gogit_submodule_cbk)(git_submodule *sm, const char *name, void *payload);
 
@@ -178,6 +179,10 @@ int _go_git_writestream_close(git_writestream *stream)
 void _go_git_writestream_free(git_writestream *stream)
 {
 	stream->free(stream);
+}
+
+git_credtype_t _go_git_cred_credtype(git_cred *cred) {
+	return cred->credtype;
 }
 
 /* EOF */
