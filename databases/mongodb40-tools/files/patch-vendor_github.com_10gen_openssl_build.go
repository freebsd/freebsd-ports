--- vendor/github.com/10gen/openssl/build.go.orig	2018-11-21 19:00:22 UTC
+++ vendor/github.com/10gen/openssl/build.go
@@ -20,5 +20,6 @@
 // #cgo CFLAGS: -Wno-deprecated-declarations
 // #cgo windows CFLAGS: -DWIN32_LEAN_AND_MEAN -I"c:/openssl/include"
 // #cgo windows LDFLAGS: -lssleay32 -llibeay32 -lcrypt32 -L "c:/openssl/bin"
+// #cgo freebsd LDFLAGS: -lssl -lcrypto
 // #cgo darwin LDFLAGS: -framework CoreFoundation -framework Foundation -framework Security
 import "C"
