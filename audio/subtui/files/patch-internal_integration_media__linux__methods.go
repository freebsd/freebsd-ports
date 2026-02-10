--- internal/integration/media_linux_methods.go.orig	2026-02-10 00:32:38 UTC
+++ internal/integration/media_linux_methods.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build linux||freebsd
 
 package integration
 
