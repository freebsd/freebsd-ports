Import https://github.com/nsf/termbox-go/commit/58d4fcbce2a7e6a3a48afbc6b7ec2a916ac33ee0
from upstream, this fixes an issue where it would hang in termui on FreeBSD.

--- vendor/github.com/awesome-gocui/termbox-go/api.go.orig	2020-05-15 14:00:27 UTC
+++ vendor/github.com/awesome-gocui/termbox-go/api.go
@@ -24,7 +24,7 @@ import "time"
 func Init() error {
 	var err error
 
-	if runtime.GOOS == "openbsd" {
+	if runtime.GOOS == "openbsd" || runtime.GOOS == "freebsd" {
 		out, err = os.OpenFile("/dev/tty", os.O_RDWR, 0)
 		if err != nil {
 			return err
