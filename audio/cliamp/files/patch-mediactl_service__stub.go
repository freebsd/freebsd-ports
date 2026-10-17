--- mediactl/service_stub.go.orig	2026-09-29 14:02:09 UTC
+++ mediactl/service_stub.go
@@ -1,4 +1,4 @@
-//go:build !linux && !windows && (!darwin || !cgo)
+//go:build !linux && !freebsd && !windows && (!darwin || !cgo)
 
 package mediactl
 
