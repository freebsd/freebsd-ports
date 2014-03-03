--- ./src/3rdparty/javascriptcore/JavaScriptCore/runtime/JSValue.h.orig	2012-12-12 20:18:36.000000000 +0100
+++ ./src/3rdparty/javascriptcore/JavaScriptCore/runtime/JSValue.h	2012-12-17 02:13:05.073285539 +0100
@@ -491,7 +491,11 @@
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
@@ -503,7 +507,11 @@
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
