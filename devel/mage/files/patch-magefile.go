--- magefile.go.orig	2018-04-11 17:03:07 UTC
+++ magefile.go
@@ -83,12 +83,14 @@ func flags() (string, error) {
 
 // tag returns the git tag for the current branch or "" if none.
 func tag() string {
+	return "%%GH_TAGNAME%%"
 	s, _ := sh.Output("git", "describe", "--tags")
 	return s
 }
 
 // hash returns the git hash for the current repo or "" if none.
 func hash() string {
+	return "%%GH_TAG_COMMIT%%"
 	hash, _ := sh.Output("git", "rev-parse", "--short", "HEAD")
 	return hash
 }
