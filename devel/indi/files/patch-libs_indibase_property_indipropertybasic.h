--- libs/indibase/property/indipropertybasic.h.orig	2022-05-21 13:52:23 UTC
+++ libs/indibase/property/indipropertybasic.h
@@ -110,7 +110,7 @@ class PropertyBasic : public INDI::Property (public)
 
     const WidgetView<T> *at(size_t index) const;
 
-    WidgetView<T> &operator[](size_t index) const;
+    WidgetView<T> &operator[](ssize_t index) const;
 
 public: // STL-style iterators
     WidgetView<T> *begin();
