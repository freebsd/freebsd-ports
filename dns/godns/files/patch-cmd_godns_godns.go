--- cmd/godns/godns.go.orig	2024-04-28 13:36:13 UTC
+++ cmd/godns/godns.go
@@ -23,11 +23,11 @@ var (
 var (
 	config  settings.Settings
 	optAddr = flag.String("a", ":9000", "Specify the address to listen on")
-	optConf = flag.String("c", "./config.json", "Specify a config file")
+	optConf = flag.String("c", "%%PREFIX%%/etc/godns-config.json", "Specify a config file")
 	optHelp = flag.Bool("h", false, "Show help")
 
 	// Version is current version of GoDNS.
-	Version = "v0.1"
+	Version = "%%DISTVERSION%%"
 )
 
 func main() {
