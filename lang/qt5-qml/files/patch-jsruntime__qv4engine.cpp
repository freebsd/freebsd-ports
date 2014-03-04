--- ./jsruntime/qv4engine.cpp.orig	2014-02-01 20:38:02.000000000 +0000
+++ ./jsruntime/qv4engine.cpp	2014-02-24 08:26:02.342458294 +0000
@@ -109,7 +112,11 @@
 #  else
     void* stackBottom = 0;
     pthread_attr_t attr;
+#if defined(Q_OS_FREEBSD)
+    pthread_attr_init(&attr);
+#else
     pthread_getattr_np(pthread_self(), &attr);
+#endif
     size_t stackSize = 0;
     pthread_attr_getstack(&attr, &stackBottom, &stackSize);
     pthread_attr_destroy(&attr);
