--- tests/test_simplesmartptr.cpp.orig	Sun Jul 15 15:51:14 2001
+++ tests/test_simplesmartptr.cpp	Sat Sep  7 10:46:20 2002
@@ -26,8 +26,8 @@
   Bogus(bool &isAlive) : _isAlive(isAlive) {}
   ~Bogus() { _isAlive = false; }
 protected:
-  friend SimpleSmartPointer< Bogus > ;
-  friend SimpleSmartPointer< const Bogus > ;
+  friend class SimpleSmartPointer< Bogus > ;
+  friend class SimpleSmartPointer< const Bogus > ;
 
   void           ref() const { _refcount.ref() ;          }
   unsigned int unref() const { return _refcount.unref() ; }
