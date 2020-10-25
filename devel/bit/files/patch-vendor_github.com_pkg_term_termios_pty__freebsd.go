--- vendor/github.com/pkg/term/termios/pty_freebsd.go.orig	2020-10-23 12:15:57 UTC
+++ vendor/github.com/pkg/term/termios/pty_freebsd.go
@@ -3,6 +3,7 @@ package termios
 import (
 	"fmt"
 	"unsafe"
+        "golang.org/x/sys/unix"
 )
 
 func posix_openpt(oflag int) (fd uintptr, err error) {
