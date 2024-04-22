--- modules/lwjgl/jemalloc/src/generated/java/org/lwjgl/system/jemalloc/JEmalloc.java.orig	2023-12-18 14:22:59 UTC
+++ modules/lwjgl/jemalloc/src/generated/java/org/lwjgl/system/jemalloc/JEmalloc.java
@@ -40,27 +40,27 @@ public class JEmalloc {
 
         /** Function address. */
         public static final long
-            malloc_message     = apiGetFunctionAddress(JEMALLOC, "je_malloc_message"),
-            malloc             = apiGetFunctionAddress(JEMALLOC, "je_malloc"),
-            calloc             = apiGetFunctionAddress(JEMALLOC, "je_calloc"),
-            posix_memalign     = apiGetFunctionAddress(JEMALLOC, "je_posix_memalign"),
-            aligned_alloc      = apiGetFunctionAddress(JEMALLOC, "je_aligned_alloc"),
-            realloc            = apiGetFunctionAddress(JEMALLOC, "je_realloc"),
-            free               = apiGetFunctionAddress(JEMALLOC, "je_free"),
-            free_sized         = apiGetFunctionAddress(JEMALLOC, "je_free_sized"),
-            free_aligned_sized = apiGetFunctionAddress(JEMALLOC, "je_free_aligned_sized"),
-            mallocx            = apiGetFunctionAddress(JEMALLOC, "je_mallocx"),
-            rallocx            = apiGetFunctionAddress(JEMALLOC, "je_rallocx"),
-            xallocx            = apiGetFunctionAddress(JEMALLOC, "je_xallocx"),
-            sallocx            = apiGetFunctionAddress(JEMALLOC, "je_sallocx"),
-            dallocx            = apiGetFunctionAddress(JEMALLOC, "je_dallocx"),
-            sdallocx           = apiGetFunctionAddress(JEMALLOC, "je_sdallocx"),
-            nallocx            = apiGetFunctionAddress(JEMALLOC, "je_nallocx"),
-            mallctl            = apiGetFunctionAddress(JEMALLOC, "je_mallctl"),
-            mallctlnametomib   = apiGetFunctionAddress(JEMALLOC, "je_mallctlnametomib"),
-            mallctlbymib       = apiGetFunctionAddress(JEMALLOC, "je_mallctlbymib"),
-            malloc_stats_print = apiGetFunctionAddress(JEMALLOC, "je_malloc_stats_print"),
-            malloc_usable_size = apiGetFunctionAddress(JEMALLOC, "je_malloc_usable_size");
+            malloc_message     = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "malloc_message"),
+            malloc             = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "malloc"),
+            calloc             = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "calloc"),
+            posix_memalign     = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "posix_memalign"),
+            aligned_alloc      = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "aligned_alloc"),
+            realloc            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "realloc"),
+            free               = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "free"),
+            free_sized         = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "free_sized"),
+            free_aligned_sized = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "free_aligned_sized"),
+            mallocx            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "mallocx"),
+            rallocx            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "rallocx"),
+            xallocx            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "xallocx"),
+            sallocx            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "sallocx"),
+            dallocx            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "dallocx"),
+            sdallocx           = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "sdallocx"),
+            nallocx            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "nallocx"),
+            mallctl            = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "mallctl"),
+            mallctlnametomib   = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "mallctlnametomib"),
+            mallctlbymib       = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "mallctlbymib"),
+            malloc_stats_print = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "malloc_stats_print"),
+            malloc_usable_size = apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "malloc_usable_size");
 
     }
 
@@ -105,11 +105,16 @@ public class JEmalloc {
     /** Use as arena index in "stats.arenas.&lt;i&gt;.*" mallctl interfaces to select destroyed arenas. */
     public static final int MALLCTL_ARENAS_DESTROYED = 0x1001;
 
+    private static String functionNamePrefix = "je_";
+
     static {
+        if (Platform.get() == Platform.FREEBSD) {
+            functionNamePrefix = "";
+        }
         // Force jemalloc to initialize before anyone else uses it.
         // This avoids a dangerous race when the first jemalloc functions are called concurrently.
         if (Platform.get() == Platform.WINDOWS) {
-            invokePV(invokePP(8L, apiGetFunctionAddress(JEMALLOC, "je_malloc")), apiGetFunctionAddress(JEMALLOC, "je_free"));
+            invokePV(invokePP(8L, apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "malloc")), apiGetFunctionAddress(JEMALLOC, functionNamePrefix + "free"));
         }
     }
 
