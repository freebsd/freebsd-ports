--- zipios++/fileentry.h.orig	Wed Aug 23 14:30:30 2000
+++ zipios++/fileentry.h	Sat Sep  7 10:46:20 2002
@@ -166,8 +166,8 @@
   class MatchName ;
   class MatchFileName ;
 protected:
-  friend SimpleSmartPointer< FileEntry > ;
-  friend SimpleSmartPointer< const FileEntry > ;
+  friend class SimpleSmartPointer< FileEntry > ;
+  friend class SimpleSmartPointer< const FileEntry > ;
   void           ref() const { _refcount.ref() ;          }
   unsigned int unref() const { return _refcount.unref() ; }
 
