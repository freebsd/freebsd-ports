--- libev/ev.c.orig    2012-09-24 16:04:11.033920205 +0400
+++ libev/ev.c 2012-09-24 15:45:30.093945530 +0400
@@ -579,6 +579,8 @@
       #define ECB_MEMORY_FENCE_RELEASE __asm__ __volatile__ ("membar #LoadStore |             #StoreStore")
     #elif defined(__s390__) || defined(__s390x__)
       #define ECB_MEMORY_FENCE         __asm__ __volatile__ ("bcr 15,0" : : : "memory")
+    #elif defined(__ia64__)
+      #define ECB_MEMORY_FENCE         __asm__ __volatile__ ("mf" : : : "memory")
     #endif
   #endif
 #endif
