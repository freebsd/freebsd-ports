--- src/pvariant.cxx.orig	Sat Dec 16 19:38:33 2006
+++ src/pvariant.cxx	Sat Dec 16 19:39:07 2006
@@ -38,7 +38,7 @@
 protected:
     int refcount;
 
-    virtual int _varray::compare(const void* key, const void* item) const;
+    virtual int compare(const void* key, const void* item) const;
 
     friend class variant;
 
