--- cmd/godns/godns.go.orig	2023-01-19 15:20:32 UTC
+++ cmd/godns/godns.go
@@ -16,11 +16,11 @@ import (
 
 var (
 	configuration settings.Settings
-	optConf       = flag.String("c", "./config.json", "Specify a config file")
+	optConf       = flag.String("c", "%%PREFIX%%/etc/godns-config.json", "Specify a config file")
 	optHelp       = flag.Bool("h", false, "Show help")
 
 	// Version is current version of GoDNS.
-	Version = "0.1"
+	Version = "%%DISTVERSION%%"
 )
 
 func init() {
