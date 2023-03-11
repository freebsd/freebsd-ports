--- go.mod.orig	2023-03-11 10:16:45 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/pydio/packr
 
-go 1.12
+go 1.17
 
 require (
 	github.com/gobuffalo/envy v1.7.0
@@ -10,4 +10,19 @@ require (
 	github.com/spf13/cobra v0.0.5
 	github.com/stretchr/testify v1.3.0
 	golang.org/x/sync v0.0.0-20190423024810-112230192c58
+)
+
+require (
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/gobuffalo/logger v1.0.0 // indirect
+	github.com/inconshreveable/mousetrap v1.0.0 // indirect
+	github.com/joho/godotenv v1.3.0 // indirect
+	github.com/karrick/godirwalk v1.10.12 // indirect
+	github.com/konsorten/go-windows-terminal-sequences v1.0.2 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/rogpeppe/go-internal v1.3.0 // indirect
+	github.com/sirupsen/logrus v1.4.2 // indirect
+	github.com/spf13/pflag v1.0.3 // indirect
+	golang.org/x/crypto v0.0.0-20190621222207-cc06ce4a13d4 // indirect
+	golang.org/x/sys v0.6.0 // indirect
 )
