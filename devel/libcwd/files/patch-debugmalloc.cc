--- debugmalloc.cc.orig	Mon Nov 10 15:42:25 2003
+++ debugmalloc.cc	Mon Nov 10 15:50:49 2003
@@ -1346,7 +1346,7 @@
       struct tm tbuf;
       tbuf_ptr = localtime_r(&alloc->a_time.tv_sec, &tbuf);
 #else
-      tbuf_ptr = localtime(&alloc->a_time.tv_sec);
+      tbuf_ptr = localtime((const time_t *)&alloc->a_time.tv_sec);
 #endif
       _private_::set_invisible_off(LIBCWD_TSD);
       --LIBCWD_DO_TSD_MEMBER_OFF(debug_object);
