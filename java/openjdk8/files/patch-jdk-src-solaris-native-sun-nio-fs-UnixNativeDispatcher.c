--- ./jdk/src/solaris/native/sun/nio/fs/UnixNativeDispatcher.c.orig	2018-12-13 10:02:37.501082000 +0100
+++ ./jdk/src/solaris/native/sun/nio/fs/UnixNativeDispatcher.c	2018-12-13 10:06:26.825382000 +0100
@@ -453,7 +453,7 @@
     (*env)->SetLongField(env, attrs, attrs_st_birthtime_sec, (jlong)buf->st_birthtime);
 #endif
 
-#if (_POSIX_C_SOURCE >= 200809L) || defined(__solaris__)
+#if (_POSIX_C_SOURCE >= 200809L) || defined(__solaris__) || defined(__FreeBSD__)
     (*env)->SetLongField(env, attrs, attrs_st_atime_nsec, (jlong)buf->st_atim.tv_nsec);
     (*env)->SetLongField(env, attrs, attrs_st_mtime_nsec, (jlong)buf->st_mtim.tv_nsec);
     (*env)->SetLongField(env, attrs, attrs_st_ctime_nsec, (jlong)buf->st_ctim.tv_nsec);
