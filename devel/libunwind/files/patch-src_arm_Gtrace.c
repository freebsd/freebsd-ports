--- src/arm/Gtrace.c.orig	2023-12-22 11:34:31 UTC
+++ src/arm/Gtrace.c
@@ -514,7 +514,9 @@ tdep_trace (unw_cursor_t *cursor, void **buffer, int *
       if (likely(ret >= 0))
         ACCESS_MEM_FAST(ret, c->validate, d, cfa + LINUX_SC_LR_OFF, lr);
 #elif defined(__FreeBSD__)
-      #error implement UNW_ARM_FRAME_SIGRETURN on FreeBSD
+      Dprintf ("%s: implement me\n", __FUNCTION__);
+      ret = -UNW_ESTOPUNWIND;
+      break;
 #endif
 
       /* Resume stack at signal restoration point. The stack is not
