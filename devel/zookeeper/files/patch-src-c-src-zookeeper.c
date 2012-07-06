Index: zookeeper.c
===================================================================
--- src/c/src/zookeeper.c	2012-07-05 15:53:43.348806000 -0400
+++ src/c/src/zookeeper.c	2012-07-05 15:55:12.800391000 -0400
@@ -413,7 +413,6 @@
 static int getaddrinfo_errno(int rc) { 
     switch(rc) {
     case EAI_NONAME:
-    case EAI_NODATA:
         return ENOENT;
     case EAI_MEMORY:
         return ENOMEM;
@@ -546,7 +545,7 @@
             //EAI_BADFLAGS or EAI_ADDRFAMILY with AF_UNSPEC and 
             // ai_flags as AI_ADDRCONFIG
             if ((hints.ai_flags == AI_ADDRCONFIG) && 
-                ((rc ==EAI_BADFLAGS) || (rc == EAI_ADDRFAMILY))) {
+                (rc ==EAI_BADFLAGS)) {
                 //reset ai_flags to null
                 hints.ai_flags = 0;
                 //retry getaddrinfo
