--- vendor/github.com/shenwei356/pand/select_other.go.orig	2023-03-24 18:40:11 UTC
+++ vendor/github.com/shenwei356/pand/select_other.go
@@ -1,7 +1,7 @@
 // we adopt the similar method to choose platform relevant function from:
 // https://github.com/clausecker/pospop
 
-//go:build !amd64 && !386
+//go:build !amd64
 
 package pand
 
