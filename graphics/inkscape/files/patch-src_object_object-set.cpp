--- src/object/object-set.cpp.orig	2021-07-04 16:28:06 UTC
+++ src/object/object-set.cpp
@@ -255,7 +255,7 @@ Inkscape::XML::Node *ObjectSet::topRepr() const
         return nullptr;
     }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
     // workaround for
     // static_assert(__is_cpp17_forward_iterator<_ForwardIterator>::value
     auto const n = std::vector<Inkscape::XML::Node *>(nodes.begin(), nodes.end());
