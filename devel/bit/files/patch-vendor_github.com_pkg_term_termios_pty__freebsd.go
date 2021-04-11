--- vendor/github.com/pkg/term/termios/pty_freebsd.go.orig	2021-04-11 08:22:30 UTC
+++ vendor/github.com/pkg/term/termios/pty_freebsd.go
@@ -3,6 +3,7 @@ package termios
 import (
 	"fmt"
 	"unsafe"
+	"golang.org/x/sys/unix"
 )
 
 func posix_openpt(oflag int) (fd uintptr, err error) {
