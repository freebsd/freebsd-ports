--- writerfilter/source/ooxml/RefAndPointer.hxx.orig	2019-09-17 22:55:25 UTC
+++ writerfilter/source/ooxml/RefAndPointer.hxx
@@ -75,13 +75,14 @@ class RefAndPointer (public)
     ChildClass * getPointer() const { return mpHandler; }
     const uno::Reference<Interface> getRef() const { return mRef; }
 
-    RefAndPointer & operator=
-    (const RefAndPointer & rSrc)
-    {
-        set(rSrc.getHandler());
-
-        return *this;
-    }
+// ...RefAndPointer.hxx:104:18: error: no member named 'getHandler' in 'RefAndPointer<Interface, ChildClass>'; did you mean 'mpHandler'?
+//    RefAndPointer & operator=
+//    (const RefAndPointer & rSrc)
+//    {
+//        set(rSrc.getHandler());
+//
+//        return *this;
+//    }
 
     bool is() { return getRef().is(); }
 
