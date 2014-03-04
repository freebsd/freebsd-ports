--- ./jsruntime/qv4mm.cpp.orig	2013-10-22 01:49:53.000000000 -0700
+++ ./jsruntime/qv4mm.cpp	2013-11-06 15:34:38.035186604 -0800
@@ -218,7 +218,11 @@
 #  else
     void* stackBottom = 0;
     pthread_attr_t attr;
+#    if OS(FREEBSD)
+    pthread_attr_init(&attr);
+#    else
     pthread_getattr_np(pthread_self(), &attr);
+#    endif
     size_t stackSize = 0;
     pthread_attr_getstack(&attr, &stackBottom, &stackSize);
     pthread_attr_destroy(&attr);
