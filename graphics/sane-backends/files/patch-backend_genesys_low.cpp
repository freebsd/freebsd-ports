Fix build on big endian archs:

genesys/low.cpp:544:9: error: 'depth' was not declared in this scope, see

https://gitlab.com/sane-project/backends/-/merge_requests/329

Obtained from:	OpenBSD

--- backend/genesys/low.cpp.orig	2020-02-02 11:58:09 UTC
+++ backend/genesys/low.cpp
@@ -539,7 +539,7 @@ Image read_unshuffled_image_from_scanner(Genesys_Devic
     }
 
 #ifdef WORDS_BIGENDIAN
-    if (depth == 16) {
+    if (session.params.depth == 16) {
         dev->pipeline.push_node<ImagePipelineNodeSwap16BitEndian>();
     }
 #endif
