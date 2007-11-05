--- lib/python/mapbase.cc.orig	2007-11-03 16:17:47.000000000 +0100
+++ lib/python/mapbase.cc	2007-11-03 16:18:22.000000000 +0100
@@ -2,30 +2,30 @@
 #include "python.h"
 
 namespace python {
-export   template<class T>
-      MapBase<T>::MapBase<T> (PyObject *pyob, bool owned): Object(pyob, owned) {
+   template<class T>
+      MapBase<T>::MapBase (PyObject *pyob, bool owned): Object(pyob, owned) {
          validate();
       }
 
-   export template<class T>
-      MapBase<T>::MapBase<T> (const MapBase<T>& ob): Object(ob) {
+    template<class T>
+      MapBase<T>::MapBase (const MapBase<T>& ob): Object(ob) {
          validate();
       }
    // Assignment acquires new ownership of pointer
 
-   export template<class T>
+    template<class T>
       MapBase<T>& MapBase<T>::operator= (const Object& rhs) {
          return (*this = *rhs);
       }
 
-   export template<class T>
+    template<class T>
       MapBase<T>& MapBase<T>::operator= (PyObject* rhsp) {
          if(ptr() == rhsp) return *this;
          set (rhsp);
          return *this;
       }
    // Membership
-   export template<class T>
+    template<class T>
       bool MapBase<T>::accepts (PyObject *pyob) const {
          return pyob && PyMapping_Check(pyob);
       }
@@ -33,7 +33,7 @@
    // Clear -- PyMapping Clear is missing
    //
 
-   export template<class T>
+    template<class T>
       void MapBase<T>::clear () {
          List k = keys();
          for(List::iterator i = k.begin(); i != k.end(); i++) {
@@ -42,54 +42,54 @@
       }      
 
    // Element Access
-   export template<class T>
+    template<class T>
       T MapBase<T>::operator[](const std::string& key) const {
          return get_item(key);
       }
 
-   export template<class T>
+    template<class T>
       T MapBase<T>::operator[](const Object& key) const {
          return get_item(key);
       }
 
-   export template<class T>
+    template<class T>
       mapref<T> MapBase<T>::operator[](const std::string& key) {
          return mapref<T>(*this, key);
       }
 
-   export template<class T>
+    template<class T>
       mapref<T> MapBase<T>::operator[](const Object& key) {
          return mapref<T>(*this, key);
       }
 
-   export template<class T>
+    template<class T>
       int MapBase<T>::length () const {
          return PyMapping_Length (ptr());
       }
 
-   export template<class T>
+    template<class T>
       int MapBase<T>::has_key (const std::string& s) const {
          return PyMapping_HasKeyString (ptr(),const_cast<char*>(s.c_str()));
       }
 
-   export template<class T>
+    template<class T>
       int MapBase<T>::has_key (const Object& s) const {
          return PyMapping_HasKey (ptr(), s.ptr());
       }
 
-   export template<class T>
+    template<class T>
       T MapBase<T>::get_item (const std::string& s) const {
          PyObject * tmp = (PyMapping_GetItemString (ptr(),const_cast<char*>(s.c_str())));
          if ( tmp == NULL ) { throw KeyError(s + " does not exist in " + this->as_string()); }
          return T( asObject(tmp));
       }
 
-   export template<class T>
+    template<class T>
       T MapBase<T>::get_item (const Object& s) const {
          return T( asObject(PyObject_GetItem (ptr(), s.ptr())));
       }
 
-   export template<class T>
+    template<class T>
       void MapBase<T>::set_item (const std::string& s, const Object& ob) {
          if (PyMapping_SetItemString (ptr(), const_cast<char*>(s.c_str()), *ob)
                == -1)
@@ -98,7 +98,7 @@
          }
       }
 
-   export template<class T>
+    template<class T>
       void MapBase<T>::set_item (const Object& s, const Object& ob) {
          if (PyObject_SetItem (ptr(), s.ptr(), ob.ptr())
                == -1)
@@ -107,31 +107,31 @@
          }
       }
 
-   export template<class T>
+    template<class T>
       void MapBase<T>::del_item (const std::string& s) {
          if (PyMapping_DelItemString (ptr(), const_cast<char*>(s.c_str())) == -1){
             throw Exception();
          }
       }
 
-   export template<class T>
+    template<class T>
       void MapBase<T>::del_item (const Object& s) {
          if (PyMapping_DelItem (ptr(), *s) == -1){
             throw Exception();
          }
       }
    // Queries
-   export template<class T>
+    template<class T>
       List MapBase<T>::keys () const {
          return List(PyMapping_Keys(ptr()), true);
       }
 
-   export template<class T>
+    template<class T>
       List MapBase<T>::values () const { // each returned item is a (key, value) pair
          return List(PyMapping_Values(ptr()), true);
       }
 
-   export template<class T>
+    template<class T>
       List MapBase<T>::items () const {
          return List(PyMapping_Items(ptr()), true);
       }	   
