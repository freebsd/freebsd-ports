--- cmd/protocol_other.go.orig	2026-09-29 14:02:09 UTC
+++ cmd/protocol_other.go
@@ -1,4 +1,4 @@
-//go:build !linux
+//go:build !linux && !freebsd
 
 package cmd
 
