--- src/shared/common/Hashtable.h.orig	Fri Sep 12 20:46:35 2003
+++ src/shared/common/Hashtable.h	Sat Sep 18 12:38:09 2004
@@ -20,8 +20,8 @@
 
   T get(const String *key) const{
     int hash = key->hashCode();
-    int bno = (hash&0x7FFFFFFF) % capacity;
-    for(HashEntry<T> *he = bucket[bno]; he != null; he = he->next)
+    int bno = (hash&0x7FFFFFFF) % this->capacity;
+    for(HashEntry<T> *he = this->bucket[bno]; he != null; he = he->next)
       if (he->hash == hash && *he->key == *key)
         return he->value;
     return null;
@@ -31,7 +31,7 @@
       Returns first element value in a sequence, or null, if hashtable is empty.
   */
   T enumerate() const{
-    T * retval = enumerate_int();
+    T * retval = this->enumerate_int();
     if (retval == null) return null;
     return *retval;
   };
@@ -40,7 +40,7 @@
       is thrown.
   */
   T next() const{
-    T *retval = next_int();
+    T *retval = this->next_int();
     if (retval == null) return null;
     return *retval;
   };
@@ -62,8 +62,8 @@
 
   const T *get(const String *key) const{
     int hash = key->hashCode();
-    int bno = (hash&0x7FFFFFFF) % capacity;
-    for(HashEntry<T> *he = bucket[bno]; he != null; he = he->next)
+    int bno = (hash&0x7FFFFFFF) % this->capacity;
+    for(HashEntry<T> *he = this->bucket[bno]; he != null; he = he->next)
       if (he->hash == hash && *he->key == *key)
         return &he->value;
     return null;
@@ -73,14 +73,14 @@
       Returns first element value in a sequence, or null, if hashtable is empty
   */
   T *enumerate() const{
-    return enumerate_int();
+    return this->enumerate_int();
   };
   /** Returns the next value object with current enumeration procedure.
       If hashtable state is changed, and next() call occurs, exception
       is thrown.
   */
   T *next() const{
-    return next_int();
+    return this->next_int();
   };
 };
 
