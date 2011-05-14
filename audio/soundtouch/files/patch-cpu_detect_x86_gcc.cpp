--- ./source/SoundTouch/cpu_detect_x86_gcc.cpp.orig	2009-01-25 18:32:53.000000000 +0200
+++ ./source/SoundTouch/cpu_detect_x86_gcc.cpp	2011-05-13 23:03:42.000000000 +0300
@@ -79,6 +79,11 @@
 
 #else
     uint res = 0;
+#ifdef __x86_64__
+    int64_t edx, eax, ecx;
+#else
+    int edx, eax, ecx;
+#endif
 
     if (_dwDisabledISA == 0xffffffff) return 0;
 
@@ -86,42 +91,55 @@
         "\n\txor     %%esi, %%esi"       // clear %%esi = result register
         // check if 'cpuid' instructions is available by toggling eflags bit 21
 
+#ifdef __x86_64__
+
         "\n\tpushf"                      // save eflags to stack
-        "\n\tpop     %%eax"              // load eax from stack (with eflags)
-        "\n\tmovl    %%eax, %%ecx"       // save the original eflags values to ecx
-        "\n\txor     $0x00200000, %%eax" // toggle bit 21
-        "\n\tpush    %%eax"              // store toggled eflags to stack
+        "\n\tpop     %2"              // load eax from stack (with eflags)
+        "\n\tmov    %2, %3"       // save the original eflags values to ecx
+        "\n\txor     $0x00200000, %2" // toggle bit 21
+        "\n\tpush    %2"              // store toggled eflags to stack
         "\n\tpopf"                       // load eflags from stack
         "\n\tpushf"                      // save updated eflags to stack
-        "\n\tpop     %%eax"              // load from stack
-        "\n\txor     %%edx, %%edx"       // clear edx for defaulting no mmx
-        "\n\tcmp     %%ecx, %%eax"       // compare to original eflags values
+        "\n\tpop     %2"              // load from stack
+#else
+
+        "\n\tpushf"                      // save eflags to stack
+        "\n\tpopl     %2"              // load eax from stack (with eflags)
+        "\n\tmovl    %2, %3"       // save the original eflags values to ecx
+        "\n\txor     $0x00200000, %2" // toggle bit 21
+        "\n\tpush    %2"              // store toggled eflags to stack
+        "\n\tpopf"                       // load eflags from stack
+        "\n\tpushf"                      // save updated eflags to stack
+        "\n\tpopl     %2"              // load from stack
+#endif
+        "\n\txor     %1, %1"       // clear edx for defaulting no mmx
+        "\n\tcmp     %3, %2"       // compare to original eflags values
         "\n\tjz      end"                // jumps to 'end' if cpuid not present
 
         // cpuid instruction available, test for presence of mmx instructions
 
-        "\n\tmovl    $1, %%eax"
+        "\n\tmov    $1, %2"
         "\n\tcpuid"
-//        movl       $0x00800000, %edx   // force enable MMX
-        "\n\ttest    $0x00800000, %%edx"
+//        movl       $0x00800000, %1   // force enable MMX
+        "\n\ttest    $0x00800000, %1"
         "\n\tjz      end"                // branch if MMX not available
 
         "\n\tor      $0x01, %%esi"       // otherwise add MMX support bit
 
-        "\n\ttest    $0x02000000, %%edx"
+        "\n\ttest    $0x02000000, %1"
         "\n\tjz      test3DNow"          // branch if SSE not available
 
         "\n\tor      $0x08, %%esi"       // otherwise add SSE support bit
 
     "\n\ttest3DNow:"
         // test for precense of AMD extensions
-        "\n\tmov     $0x80000000, %%eax"
+        "\n\tmov     $0x80000000, %2"
         "\n\tcpuid"
         "\n\tcmp     $0x80000000, %%eax"
         "\n\tjbe     end"                 // branch if no AMD extensions detected
 
         // test for precense of 3DNow! extension
-        "\n\tmov     $0x80000001, %%eax"
+        "\n\tmov     $0x80000001, %2"
         "\n\tcpuid"
         "\n\ttest    $0x80000000, %%edx"
         "\n\tjz      end"                  // branch if 3DNow! not detected
@@ -132,9 +150,9 @@
 
         "\n\tmov     %%esi, %0"
 
-      : "=r" (res)
+      : "=r" (res), "=d" (edx), "=a" (eax), "=c" (ecx)
       : /* no inputs */
-      : "%edx", "%eax", "%ecx", "%esi" );
+      : "%esi");
       
     return res & ~_dwDisabledISA;
 #endif
