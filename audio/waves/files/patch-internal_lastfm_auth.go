--- internal/lastfm/auth.go.orig	1979-11-29 23:00:00 UTC
+++ internal/lastfm/auth.go
@@ -108,6 +108,8 @@ func OpenBrowser(url string) error {
 	switch runtime.GOOS {
 	case "darwin":
 		cmd = exec.Command("open", url)
+	case "freebsd":
+		cmd = exec.Command("xdg-open", url)
 	case "linux":
 		cmd = exec.Command("xdg-open", url)
 	case "windows":
