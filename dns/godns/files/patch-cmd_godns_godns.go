--- cmd/godns/godns.go.orig	2024-02-04 03:14:27 UTC
+++ cmd/godns/godns.go
@@ -22,11 +22,11 @@ var (
 
 var (
 	config  settings.Settings
-	optConf = flag.String("c", "./config.json", "Specify a config file")
+	optConf = flag.String("c", "%%PREFIX%%/etc/godns-config.json", "Specify a config file")
 	optHelp = flag.Bool("h", false, "Show help")
 
 	// Version is current version of GoDNS.
-	Version = "0.1"
+	Version = "%%DISTVERSION%%"
 )
 
 func init() {
