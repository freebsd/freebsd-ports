--- internal/integration/media_linux_props.go.orig	2026-02-10 00:33:05 UTC
+++ internal/integration/media_linux_props.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build linux||freebsd
 
 package integration
 
