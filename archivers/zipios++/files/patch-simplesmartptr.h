--- zipios++/simplesmartptr.h.orig	Sun Jul 15 15:42:34 2001
+++ zipios++/simplesmartptr.h	Sat Sep  7 10:46:20 2002
@@ -99,13 +99,14 @@
 class ReferenceCount {
   /** SimpleSmartPointer needs to be a friend to invoke the private
       ref() and unref() methods.  */
-  friend SimpleSmartPointer< Type > ;
-  friend SimpleSmartPointer< const Type > ;
+  friend class SimpleSmartPointer< Type > ;
+  friend class SimpleSmartPointer< const Type > ;
   /** Type also needs to be a friend to invoke the private ref() and
       unref() methods, in case Type doesn't want to inherit
       ReferenceCount and thus needs to invoke ref() and unref()
       through forwarding member functions. */
-  friend Type ;
+  /* Note: template parameters cannot be friends */
+  //friend Type ;
 public:
   /** Constructor intializes count to zero. */
   ReferenceCount() : _ref_count( 0 ) {}
@@ -117,7 +118,6 @@
   /** The assignment operator doesn't copy the reference count, it
       leaves it unchanged.  */
   const ReferenceCount &operator= ( const ReferenceCount &src ) {}
-private:
 
   /** Increases the reference count. */
   void ref() const           { ++_ref_count ;        }
@@ -127,6 +127,8 @@
 
   /** Returns the reference count - For debugging purposes. */
   unsigned int getReferenceCount() const { return _ref_count; }
+
+private:
 
   /** Holds the actual reference count */
   mutable unsigned short _ref_count ;
