--- vendor/github.com/charmbracelet/bubbletea/cancelreader_select.go.orig	2021-10-30 17:04:27 UTC
+++ vendor/github.com/charmbracelet/bubbletea/cancelreader_select.go
@@ -1,5 +1,5 @@
-//go:build solaris || darwin
-// +build solaris darwin
+//go:build solaris || darwin || freebsd || netbsd || openbsd
+// +build solaris darwin freebsd netbsd openbsd
 
 // nolint:revive
 package tea
