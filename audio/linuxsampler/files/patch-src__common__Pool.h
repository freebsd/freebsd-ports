--- src/common/Pool.h.orig	2008-12-07 09:18:04.000000000 +0900
+++ src/common/Pool.h	2012-10-13 04:19:19.000000000 +0900
@@ -393,7 +393,7 @@
         inline Iterator allocAppend() {
             if (pPool->poolIsEmpty()) return RTListBase<T>::begin();
             Iterator element = pPool->alloc();
-            append(element);
+            this->append(element);
             #if CONFIG_DEVMODE
             element.list = this;
             #endif // CONFIG_DEVMODE
