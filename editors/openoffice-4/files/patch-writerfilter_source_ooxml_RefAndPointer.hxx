--- writerfilter/source/ooxml/RefAndPointer.hxx.orig	2021-04-02 12:58:23 UTC
+++ writerfilter/source/ooxml/RefAndPointer.hxx
@@ -98,13 +98,14 @@ class RefAndPointer (public)
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
 
