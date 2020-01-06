--- vendor/github.com/zyedidia/pty/ztypes_freebsd_arm64.go.orig	2019-12-23 19:57:30.388608000 +0100
+++ vendor/github.com/zyedidia/pty/ztypes_freebsd_arm64.go	2019-12-23 19:56:25.521268000 +0100
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
