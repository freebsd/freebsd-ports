--- include/loki/Threads.h.orig	Mon Nov  6 20:39:26 2006
+++ include/loki/Threads.h	Mon Nov  6 20:42:26 2006
@@ -51,8 +51,8 @@
 
 #include <cassert>
 
-#if defined(LOKI_CLASS_LEVEL_THREADING) || defined(LOKI_OBJECT_LEVEL_THREADING)
-
+//#if defined(LOKI_CLASS_LEVEL_THREADING) || defined(LOKI_OBJECT_LEVEL_THREADING)
+#if 0
     #define LOKI_DEFAULT_THREADING_NO_OBJ_LEVEL ::Loki::ClassLevelLockable
     
     #if defined(LOKI_CLASS_LEVEL_THREADING) && !defined(LOKI_OBJECT_LEVEL_THREADING)
