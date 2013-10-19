--- checkvm/checkvm.c.orig
+++ checkvm/checkvm.c
@@ -56,7 +56,7 @@
     uint32       val
 )
 {
-  __asm__ volatile("out%L0 (%%dx)" : :"a" (val), "d" (port));
+  __asm__ volatile("outl %%eax, %%dx" : :"a" (val), "d" (port));
 }
 
 static __inline__ uint32
@@ -66,7 +66,7 @@
 {
   uint32 ret;
 
-  __asm__ volatile("in%L0 (%%dx)" : "=a" (ret) : "d" (port));
+  __asm__ volatile("inl %%dx, %%eax" : "=a" (ret) : "d" (port));
   return ret;
 }
 
@@ -79,7 +79,7 @@
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    	            "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETVERSION),
 		    "2"(BDOOR_PORT) : "memory");
@@ -96,7 +96,7 @@
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    	            "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETHWVERSION),
 		    "2"(BDOOR_PORT) : "memory");
@@ -112,7 +112,7 @@
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    		    "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETSCREENSIZE),
 		    "2"(BDOOR_PORT) : "memory");
