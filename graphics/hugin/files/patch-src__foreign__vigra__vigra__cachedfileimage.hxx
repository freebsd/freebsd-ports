--- src/foreign/vigra/vigra/cachedfileimage.hxx.orig	2012-11-12 13:33:18.000000000 +0200
+++ src/foreign/vigra/vigra/cachedfileimage.hxx	2012-11-12 13:34:44.000000000 +0200
@@ -555,7 +555,7 @@
 class NotifyingDirectionSelector<UnstridedArrayTag, T, Notify>
 {
 #ifdef __GNUC__
-friend class Notify::self_type;
+friend class Notify::CachedFileImageIteratorBase;
 #else
 friend typename Notify::self_type;
 #endif
