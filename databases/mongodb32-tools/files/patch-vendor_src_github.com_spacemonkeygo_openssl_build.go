--- vendor/src/github.com/spacemonkeygo/openssl/build.go.orig	2016-08-30 17:14:55 UTC
+++ vendor/src/github.com/spacemonkeygo/openssl/build.go
@@ -19,5 +19,6 @@ package openssl
 // #cgo linux pkg-config: openssl
 // #cgo windows CFLAGS: -DWIN32_LEAN_AND_MEAN
 // #cgo darwin CFLAGS: -Wno-deprecated-declarations
+// #cgo freebsd LDFLAGS: -lssl -lcrypto
 // #cgo darwin LDFLAGS: -lssl -lcrypto
 import "C"
