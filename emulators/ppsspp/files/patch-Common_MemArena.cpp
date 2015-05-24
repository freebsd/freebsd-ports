--- Common/MemArena.cpp.orig	2015-02-26 20:05:06 UTC
+++ Common/MemArena.cpp
@@ -189,7 +189,7 @@ void *MemArena::CreateView(s64 offset, s
 // Do not sync memory to underlying file. Linux has this by default.
 #ifdef BLACKBERRY
 		MAP_NOSYNCFILE |
-#elif defined(__FreeBSD__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
 		MAP_NOSYNC |
 #endif
 		((base == 0) ? 0 : MAP_FIXED), fd, offset);
