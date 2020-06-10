--- ../../gotools-102fdcc65de/vendor/github.com/creack/pty/ztypes_freebsd_arm64.go.orig	2020-06-09 19:34:35 UTC
+++ ../../gotools-102fdcc65de/vendor/github.com/creack/pty/ztypes_freebsd_arm64.go
@@ -0,0 +1,13 @@
+// Created by cgo -godefs - DO NOT EDIT
+// cgo -godefs types_freebsd.go
+
+package pty
+
+const (
+	_C_SPECNAMELEN = 0x3f
+)
+
+type fiodgnameArg struct {
+	Len       int32
+	Buf       *byte
+}
