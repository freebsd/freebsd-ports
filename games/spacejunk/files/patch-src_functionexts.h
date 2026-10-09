--- src/functionexts.h.orig	2010-05-12 18:35:20 UTC
+++ src/functionexts.h
@@ -429,7 +429,7 @@ private:
     bool * iterating;
     bool _iterating;
     Container * c;
-    erase_iterator & operator = (const erase_iterator &ei) const {
+    erase_iterator & operator = (const erase_iterator &ei) {
         c=ei.c;
         iterating=ei.iterating;
         _iterating=ei._iterating;
