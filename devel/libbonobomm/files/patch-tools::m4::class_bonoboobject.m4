--- tools/m4/class_bonoboobject.m4.orig	Tue Aug 17 17:57:29 2004
+++ tools/m4/class_bonoboobject.m4	Tue Aug 17 17:58:19 2004
@@ -200,7 +200,7 @@
 ')dnl
 
 private:
-  friend class CppClassType;
+  friend class __CPPNAME__`'_Class;
   static CppClassType `'__BASE__`'_class_;
 
   __CPPNAME__`'(const __CPPNAME__&);
