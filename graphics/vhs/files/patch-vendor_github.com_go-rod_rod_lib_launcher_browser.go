--- vendor/github.com/go-rod/rod/lib/launcher/browser.go.orig	2023-03-07 14:57:56 UTC
+++ vendor/github.com/go-rod/rod/lib/launcher/browser.go
@@ -303,6 +303,10 @@ func LookPath() (found string, has bool) {
 			"/usr/bin/chromium-browser",
 			"/snap/bin/chromium",
 		},
+		"freebsd": {
+			"chrome",
+			"ungoogled-chromium",
+		},
 		"windows": append([]string{"chrome", "edge"}, expandWindowsExePaths(
 			`Google\Chrome\Application\chrome.exe`,
 			`Chromium\Application\chrome.exe`,
