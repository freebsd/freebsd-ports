--- internal/mpris/mpris_test.go.orig	1979-11-29 23:00:00 UTC
+++ internal/mpris/mpris_test.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build (linux || freebsd)
 
 package mpris
 
