--- jfrog-cli/utils/lock/utils_unix.go.orig	2018-11-09 16:18:19 UTC
+++ jfrog-cli/utils/lock/utils_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build linux darwin freebsd
 
 package lock
 
