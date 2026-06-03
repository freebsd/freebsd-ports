--- vendor/github.com/tree-sitter/go-tree-sitter/dup_unix.go.orig	2026-04-11 04:15:35 UTC
+++ vendor/github.com/tree-sitter/go-tree-sitter/dup_unix.go
@@ -1,4 +1,4 @@
-//go:build linux || darwin
+//go:build linux || darwin || freebsd
 
 package tree_sitter
 
