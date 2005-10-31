--- gcc/config/i386/i386.c.orig	Sun Dec 12 13:00:44 2004
+++ gcc/config/i386/i386.c	Sun Oct 30 21:04:51 2005
@@ -1017,4 +1017,11 @@ override_options ()
       {"athlon-mp", PROCESSOR_ATHLON, PTA_MMX | PTA_PREFETCH_SSE | PTA_3DNOW
 				      | PTA_3DNOW_A | PTA_SSE},
+      {"k8", PROCESSOR_ATHLON, PTA_MMX | PTA_PREFETCH_SSE | PTA_3DNOW
+				      | PTA_3DNOW_A | PTA_SSE | PTA_SSE2},
+
+      {"opteron", PROCESSOR_ATHLON, PTA_MMX | PTA_PREFETCH_SSE | PTA_3DNOW
+				      | PTA_3DNOW_A | PTA_SSE | PTA_SSE2},
+      {"athlon64", PROCESSOR_ATHLON, PTA_MMX | PTA_PREFETCH_SSE | PTA_3DNOW
+				      | PTA_3DNOW_A | PTA_SSE | PTA_SSE2},
     };
 
