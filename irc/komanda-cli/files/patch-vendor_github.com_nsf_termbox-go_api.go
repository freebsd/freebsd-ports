--- vendor/github.com/nsf/termbox-go/api.go.orig	2020-05-15 19:17:07 UTC
+++ vendor/github.com/nsf/termbox-go/api.go
@@ -24,7 +24,7 @@ import "time"
 func Init() error {
 	var err error
 
-	if runtime.GOOS == "openbsd" {
+	if runtime.GOOS == "openbsd" || runtime.GOOS == "freebsd" {
 		out, err = os.OpenFile("/dev/tty", os.O_RDWR, 0)
 		if err != nil {
 			return err
