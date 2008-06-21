--- ./Global/GlobalDefinitions.h.orig	2004-03-01 13:51:28.000000000 -0300
+++ ./Global/GlobalDefinitions.h	2008-06-12 15:39:31.000000000 -0300
@@ -726,8 +726,6 @@
 template <typename T> class Allocator
 {
 public:
-  typedef T MyType;
-
   Allocator( T** ptr, const string& name, ostream& monStream=cerr ) : 
     ptr_(ptr), name_(name), size_(0), isAllocated_(false), 
     monStream_( monStream )
@@ -788,32 +786,34 @@
  
   virtual void allocate( unsigned long size )
   {
-    size_=size;
-    (*ptr_)=new T[size_];
-    isAllocated_=true;
+    Allocator<T>::size_=size;
+    (*Allocator<T>::ptr_)=new T[Allocator<T>::size_];
+    Allocator<T>::isAllocated_=true;
   }
 
   virtual void allocateAndZero( unsigned long size ) 
   {
     const unsigned char zero(0);
     allocate(size);
-    memset( (void*)(*ptr_), zero, size_*sizeof(MyType) );
+    memset( (void*)(*Allocator<T>::ptr_), zero, Allocator<T>::size_*sizeof(T) );
   }
   virtual void load( unsigned long size )
   {
     allocate(size);
-    loadFromFile( name_, (char*)(*ptr_), size_*sizeof(MyType), monStream_ );
+    loadFromFile( Allocator<T>::name_, (char*)(*Allocator<T>::ptr_),
+        Allocator<T>::size_*sizeof(T), Allocator<T>::monStream_ );
   }
   virtual void save()
   {
-    saveToFile( name_, (char*)(*ptr_), size_*sizeof(MyType), monStream_ );
+    saveToFile( Allocator<T>::name_, (char*)(*Allocator<T>::ptr_),
+        Allocator<T>::size_*sizeof(T), Allocator<T>::monStream_ );
   }
 
   virtual void deallocate()
   {
-    if (!isAllocated_) return;
-    delete [] (*ptr_);
-    isAllocated_=false;
+    if (!Allocator<T>::isAllocated_) return;
+    delete [] (*Allocator<T>::ptr_);
+    Allocator<T>::isAllocated_=false;
   }
 protected:
 };
@@ -892,7 +892,7 @@
     if (isAllocated_) return;
     mode_ = MemoryMapper::createMap;
     size_ = size;
-    (*ptr_) = (T*) linkToMap(mode_,name_,size_*sizeof(MyType));
+    (*ptr_) = (T*) linkToMap(mode_,name_,size_*sizeof(T));
     isAllocated_ = true;
   }
 
@@ -908,7 +908,7 @@
     if (isAllocated_) return;
     mode_ = MemoryMapper::readMap;
     size_ = size;
-    (*ptr_) = (T*) linkToMap(mode_,name_,size_*sizeof(MyType));
+    (*ptr_) = (T*) linkToMap(mode_,name_,size_*sizeof(T));
     isAllocated_ = true;
   }
 
@@ -921,7 +921,7 @@
   virtual void deallocate()
   {
     if (!isAllocated_) return;
-    if(munmap((caddr_t)(*ptr_), size_*sizeof(MyType)) < 0)
+    if(munmap((caddr_t)(*ptr_), size_*sizeof(T)) < 0)
       perror("unmap error"); // don't throw - called from destructor!
     close(fileDesc_);
     if (mode_.deleteFileOnExit) shm_unlink(name_.c_str());
