--- src/setlist.h.orig	2015-07-03 20:03:50 UTC
+++ src/setlist.h
@@ -35,7 +35,11 @@ public:
     SetList(Glib::ustring ext){extension=ext;};
     ~SetList()
       {
+#if defined(_LIBCPP_VERSION)
+        for (typename SetList<T>::iterator it = this->begin(); it != this->end();
+#else
         for (class SetList<T>::iterator it = this->begin(); it != this->end();
+#endif
              it++)
           delete (*it);
       };
@@ -62,7 +66,11 @@ public:
 
     bool contains(Glib::ustring name) const
       {
+#if defined(_LIBCPP_VERSION)
+        for (typename SetList<T>::const_iterator it = this->begin(); 
+#else
         for (class SetList<T>::const_iterator it = this->begin(); 
+#endif
              it != this->end(); it++)
           if ((*it)->getName() == name)
             return true;
