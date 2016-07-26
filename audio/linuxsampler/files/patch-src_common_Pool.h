--- src/common/Pool.h.orig	2008-12-07 00:18:04 UTC
+++ src/common/Pool.h
@@ -393,7 +393,7 @@ class RTList : public RTListBase<T> {
         inline Iterator allocAppend() {
             if (pPool->poolIsEmpty()) return RTListBase<T>::begin();
             Iterator element = pPool->alloc();
-            append(element);
+            this->append(element);
             #if CONFIG_DEVMODE
             element.list = this;
             #endif // CONFIG_DEVMODE
