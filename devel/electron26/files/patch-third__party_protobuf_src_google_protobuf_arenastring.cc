--- third_party/protobuf/src/google/protobuf/arenastring.cc.orig	2022-09-01 14:18:43 UTC
+++ third_party/protobuf/src/google/protobuf/arenastring.cc
@@ -64,7 +64,9 @@ constexpr size_t kNewAlign = alignof(std::max_align_t)
 #endif
 constexpr size_t kStringAlign = alignof(std::string);
 
+#if !(defined(__FreeBSD__) && defined(__i386__))
 static_assert((kStringAlign > kNewAlign ? kStringAlign : kNewAlign) >= 8, "");
+#endif
 static_assert(alignof(ExplicitlyConstructedArenaString) >= 8, "");
 
 }  // namespace
