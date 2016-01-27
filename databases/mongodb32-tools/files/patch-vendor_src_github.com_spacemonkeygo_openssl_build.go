--- vendor/src/github.com/spacemonkeygo/openssl/build.go.orig	2016-01-03 17:52:18 UTC
+++ vendor/src/github.com/spacemonkeygo/openssl/build.go
@@ -19,4 +19,5 @@ package openssl
 // #cgo linux pkg-config: openssl
 // #cgo windows CFLAGS: -DWIN32_LEAN_AND_MEAN
 // #cgo darwin LDFLAGS: -lssl -lcrypto
+// #cgo freebsd LDFLAGS: -lssl -lcrypto
 import "C"
