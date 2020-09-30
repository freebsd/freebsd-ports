--- src/engine.h.orig	2012-05-19 10:26:56 UTC
+++ src/engine.h
@@ -44,7 +44,7 @@
 
 #define VERTEX_DRAW_INNER_OFFSET 	0.15f
 
-char debugOutput[1024];
+extern char debugOutput[1024];
 
 #include "renderstate.h"
 
