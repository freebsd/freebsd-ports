--- src/llfuse.c.orig	2022-05-31 15:39:27 UTC
+++ src/llfuse.c
@@ -41836,7 +41836,7 @@ static void *__pyx_f_6llfuse_worker_start(void *__pyx_
  *                   'aborting processing', tid)
  */
         __pyx_t_7 = __pyx_v_wd->thread_id;
-        __pyx_v_tid = __pyx_t_7;
+        __pyx_v_tid = (uintptr_t)__pyx_t_7;
 
         /* "src/fuse_api.pxi":391
  *         fuse_session_exit(session)
