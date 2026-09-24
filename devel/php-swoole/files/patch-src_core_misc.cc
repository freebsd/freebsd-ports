--- src/core/misc.cc.orig	2026-09-23 14:51:03 UTC
+++ src/core/misc.cc
@@ -172,7 +172,7 @@ int sw_atomic_futex_wait(sw_atomic_t *atomic, double t
                 return -1;
             }
         } while (0);
-        sw_usleep(1000);
+        usleep(1000);
     }
 }
 
