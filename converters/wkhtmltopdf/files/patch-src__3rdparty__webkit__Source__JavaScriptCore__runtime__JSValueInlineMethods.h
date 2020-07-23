--- src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSValueInlineMethods.h.orig	2018-05-29 06:56:52 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSValueInlineMethods.h
@@ -227,7 +227,11 @@ namespace JSC {
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(ptr);
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+#endif
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
@@ -239,7 +243,11 @@ namespace JSC {
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(const_cast<JSCell*>(ptr));
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(const_cast<JSCell*>(ptr));
+#endif
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
