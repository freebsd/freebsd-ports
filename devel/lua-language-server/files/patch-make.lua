--- make.lua.orig	2022-09-06 18:48:12 UTC
+++ make.lua
@@ -96,6 +96,5 @@ lm:build 'unit-test' {
 }
 
 lm:default {
-    "bee-test",
-    "unit-test",
+    "all"
 }
