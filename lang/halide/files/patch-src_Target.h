--- src/Target.h.orig	2022-08-17 04:44:15 UTC
+++ src/Target.h
@@ -23,6 +23,7 @@ struct Target {
     enum OS {
         OSUnknown = 0,
         Linux,
+        FreeBSD,
         Windows,
         OSX,
         Android,
