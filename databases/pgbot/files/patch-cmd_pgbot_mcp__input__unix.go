--- cmd/pgbot/mcp_input_unix.go.orig
+++ cmd/pgbot/mcp_input_unix.go
@@ -1,4 +1,4 @@
-//go:build darwin || linux
+//go:build darwin || freebsd || linux
 
 package main
 
