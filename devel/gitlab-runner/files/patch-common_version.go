--- common/version.go.orig	2017-03-22 15:25:34 UTC
+++ common/version.go
@@ -10,9 +10,9 @@ import (
 )
 
 var NAME = "gitlab-ci-multi-runner"
-var VERSION = "dev"
-var REVISION = "HEAD"
-var BRANCH = "HEAD"
+var VERSION = "%%VERSION%%"
+var REVISION = "%%REVISION%%"
+var BRANCH = "%%BRANCH%%"
 var BUILT = "now"
 
 var AppVersion AppVersionInfo
