--- internal/cmd/cmd.go.orig	2019-11-02 05:10:13 UTC
+++ internal/cmd/cmd.go
@@ -139,7 +139,7 @@ func getRootCommand(develMode bool, exitCodeAddr *int,
 
 func checkOS() error {
 	switch runtime.GOOS {
-	case "darwin", "linux":
+	case "darwin", "linux", "freebsd":
 		return nil
 	default:
 		return fmt.Errorf("%s is not a supported operating system", runtime.GOOS)
