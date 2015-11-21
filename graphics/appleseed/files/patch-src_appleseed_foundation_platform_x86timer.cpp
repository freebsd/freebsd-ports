--- src/appleseed/foundation/platform/x86timer.cpp.orig	2015-11-03 13:40:41 UTC
+++ src/appleseed/foundation/platform/x86timer.cpp
@@ -105,16 +105,26 @@ uint64 X86Timer::read_start()
 // gcc.
 #elif defined __GNUC__
 
-    uint32 h, l;
+    uint32 h, l, _dummy;
 
+    // %ebx may be used to point to GOT for PIC on 32-bit x86, so it must be
+    // preserved (cf. src/appleseed/foundation/platform/system.cpp).
+    // We force in-order execution of the RDTSC instruction by calling CPUID
+    // first.  Reference: "Using the RDTSC Instruction for Performance
+    // Monitoring", Section 3.1, p. 3 [Intel 1997].
     asm volatile (
-        "cpuid\n\t"                         // force in-order execution of the RDTSC instruction
-        "rdtsc\n\t"
-        "mov %%edx, %0\n\t"
-        "mov %%eax, %1\n\t"
-        : "=r" (h), "=r" (l)                // outputs
-        :                                   // inputs
-        : "%rax", "%rbx", "%rcx", "%rdx"    // clobbered registers
+#if __x86_64__
+        "movq %%rbx, %q2\n\t"
+        "cpuid\n\t"
+        "xchgq %%rbx, %q2\n\t"
+#else
+        "movl %%ebx, %2\n\t"
+        "cpuid\n\t"
+        "xchgl %%ebx, %2\n\t"
+#endif
+        "rdtsc"
+        : "=d" (h), "=a" (l), "=r" (_dummy)
+      : : "ecx"
     );
 
     return (static_cast<uint64>(h) << 32) | l;
@@ -158,16 +168,27 @@ uint64 X86Timer::read_end()
 // gcc.
 #elif defined __GNUC__
 
-    uint32 h, l;
+    uint32 h, l, _dummy;
 
+    // Here we call CPUID to prevent instructions coming afterward from
+    // executing before the RDTSCP instruction.  Reference: "How to
+    // Benchmark Code Execution Times on Intel IA-32 and IA-64 Instruction
+    // Set Architectures", Section 3.2.1, p. 16 [Intel 2010].
     asm volatile (
         "rdtscp\n\t"
-        "mov %%edx, %0\n\t"
-        "mov %%eax, %1\n\t"
-        "cpuid\n\t"                         // prevent instructions coming afterward from executing before the RDTSCP instruction
-        : "=r" (h), "=r" (l)                // outputs
-        :                                   // inputs
-        : "%rax", "%rbx", "%rcx", "%rdx"    // clobbered registers
+        "movl %%edx, %0\n\t"
+        "movl %%eax, %1\n\t"
+#if __x86_64__
+        "movq %%rbx, %q2\n\t"
+        "cpuid\n\t"
+        "xchgq %%rbx, %q2\n\t"
+#else
+        "movl %%ebx, %2\n\t"
+        "cpuid\n\t"
+        "xchgl %%ebx, %2\n\t"
+#endif
+        : "=m" (h), "=m" (l), "=r" (_dummy)
+        : : "eax", "ecx", "edx"
     );
 
     return (static_cast<uint64>(h) << 32) | l;
