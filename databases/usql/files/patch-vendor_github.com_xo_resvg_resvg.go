--- vendor/github.com/xo/resvg/resvg.go.orig	2024-10-23 09:08:34 UTC
+++ vendor/github.com/xo/resvg/resvg.go
@@ -10,6 +10,7 @@ package resvg
 #cgo linux,amd64 LDFLAGS: -L${SRCDIR}/libresvg/linux_amd64 -lresvg -lm
 #cgo linux,arm64 LDFLAGS: -L${SRCDIR}/libresvg/linux_arm64 -lresvg -lm
 #cgo linux,arm LDFLAGS: -L${SRCDIR}/libresvg/linux_arm -lresvg -lm
+#cgo freebsd,amd64 LDFLAGS: -L${SRCDIR}/libresvg/freebsd_amd64 -lresvg -lm
 #cgo windows,amd64 LDFLAGS: -L${SRCDIR}/libresvg/windows_amd64 -lresvg -lm -lkernel32 -ladvapi32 -lbcrypt -lntdll -luserenv -lws2_32
 
 #include <stdlib.h>
