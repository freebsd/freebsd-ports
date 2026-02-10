--- internal/integration/media_freebsd.go.orig	2026-02-10 00:31:29 UTC
+++ internal/integration/media_freebsd.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build linux||freebsd
 
 package integration
 
