In file included from bindings/python/qrosspython/cxx/cxxsupport.cxx:38:
bindings/python/qrosspython/cxx/Objects.hxx:1081:15: 
	error: cannot initialize a member subobject of type 'int' with an rvalue of type 'nullptr_t'
            , offset( NULL )

--- bindings/python/qrosspython/cxx/Objects.hxx.orig	2018-02-18 08:21:27 UTC
+++ bindings/python/qrosspython/cxx/Objects.hxx
@@ -1078,7 +1078,7 @@ namespace Py
         // TMM: added this seqref ctor for use with STL algorithms
         seqref (Object& obj)
             : s(dynamic_cast< SeqBase<T>&>(obj))
-            , offset( NULL )
+            , offset( 0 )
             , the_item(s.getItem(offset))
         {}
         ~seqref()
