--- main.go.orig	2021-11-02 05:13:52 UTC
+++ main.go
@@ -17,7 +17,7 @@ import (
 )
 
 var addr = flag.String("listen-address", ":9204", "Prometheus metrics port")
-var conf = flag.String("config", "/etc/dnssec-checks", "Configuration file")
+var conf = flag.String("config", "%%PREFIX%%/etc/prometheus-dnssec-checks", "Configuration file")
 var resolvers = flag.String("resolvers", "8.8.8.8:53,1.1.1.1:53", "Resolvers to use (comma separated)")
 var timeout = flag.Duration("timeout", 10*time.Second, "Timeout for network operations")
 
