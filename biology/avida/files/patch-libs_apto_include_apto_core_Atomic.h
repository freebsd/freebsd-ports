--- libs/apto/include/apto/core/Atomic.h.orig	2012-09-29 03:33:38 UTC
+++ libs/apto/include/apto/core/Atomic.h
@@ -88,6 +88,25 @@ inline void Apto::Atomic::Set(volatile i
   *atomic = value;
 }
 
+#elif defined __GNUC__
+
+inline int Apto::Atomic::Add(volatile int* atomic, int value)
+{
+  return __sync_add_and_fetch(atomic, value);
+}
+
+inline int Apto::Atomic::Get(volatile int* atomic)
+{
+  __sync_synchronize();
+  return *atomic;
+}
+
+inline void Apto::Atomic::Set(volatile int* atomic, int value)
+{
+  __sync_synchronize();
+  *atomic = value;
+}
+
 #else
 
 // Assuming x86
