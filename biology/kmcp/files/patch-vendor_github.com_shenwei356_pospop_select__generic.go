--- vendor/github.com/shenwei356/pospop/select_generic.go.orig	2023-03-23 01:18:29 UTC
+++ vendor/github.com/shenwei356/pospop/select_generic.go
@@ -7,6 +7,3 @@ package pospop
 
 // generic variants only
 var count8funcs = []count8impl{{count8generic, "generic", true}}
-var count16funcs = []count16impl{{count16generic, "generic", true}}
-var count32funcs = []count32impl{{count32generic, "generic", true}}
-var count64funcs = []count64impl{{count64generic, "generic", true}}
