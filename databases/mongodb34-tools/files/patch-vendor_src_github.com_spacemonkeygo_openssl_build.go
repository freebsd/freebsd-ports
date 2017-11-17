--- vendor/src/github.com/spacemonkeygo/openssl/build.go.orig	2017-07-31 19:00:22 UTC
+++ vendor/src/github.com/spacemonkeygo/openssl/build.go
@@ -19,6 +19,7 @@ package openssl
 // #cgo linux pkg-config: openssl
 // #cgo windows CFLAGS: -DWIN32_LEAN_AND_MEAN
 // #cgo windows LDFLAGS: -lcrypt32
+// #cgo freebsd LDFLAGS: -lssl -lcrypto
 // #cgo darwin CFLAGS: -Wno-deprecated-declarations
 // #cgo darwin LDFLAGS: -lssl -lcrypto -framework CoreFoundation -framework Foundation -framework Security
 import "C"
