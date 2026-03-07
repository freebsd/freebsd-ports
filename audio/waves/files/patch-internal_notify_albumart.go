--- internal/notify/albumart.go.orig	1979-11-29 23:00:00 UTC
+++ internal/notify/albumart.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build (linux || freebsd)
 
 package notify
 
