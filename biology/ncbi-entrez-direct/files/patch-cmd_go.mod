--- cmd/go.mod.orig	2023-03-08 17:07:24 UTC
+++ cmd/go.mod
@@ -1,6 +1,6 @@
 module edirect
 
-go 1.15
+go 1.17
 
 replace eutils => ../eutils
 
@@ -8,7 +8,17 @@ require (
 	eutils v0.0.0-00010101000000-000000000000
 	github.com/fatih/color v1.10.0
 	github.com/fiam/gounidecode v0.0.0-20150629112515-8deddbd03fec
+	github.com/surgebase/porter2 v0.0.0-20150829210152-56e4718818e8
+)
+
+require (
+	github.com/gedex/inflector v0.0.0-20170307190818-16278e9db813 // indirect
+	github.com/klauspost/cpuid v1.3.1 // indirect
+	github.com/mattn/go-colorable v0.1.8 // indirect
+	github.com/mattn/go-isatty v0.0.12 // indirect
+	github.com/pbnjay/memory v0.0.0-20201129165224-b12e5d931931 // indirect
 	github.com/stretchr/testify v1.7.0 // indirect
 	github.com/surge/glog v0.0.0-20141108051140-2578deb2b95c // indirect
-	github.com/surgebase/porter2 v0.0.0-20150829210152-56e4718818e8
+	golang.org/x/sys v0.5.0 // indirect
+	golang.org/x/text v0.3.5 // indirect
 )
