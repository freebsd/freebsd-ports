
$FreeBSD$

--- src/reader.hpp.orig
+++ src/reader.hpp
@@ -33,12 +33,6 @@
 
 #include "local.h"
 
-#ifdef DEBUG
-#define INLINE
-#else
-#define INLINE inline
-#endif
-
 typedef vector<uchar> ReadBuffer;
 
 #ifdef __GNUC__
@@ -54,12 +48,12 @@
   bool open(const string& filename);
   bool close();
   bool eof();
-  INLINE bool is_open() const;
+  bool is_open() const;
   
   size_t read( ReadBuffer& v, size_t numBytes );
   off_t  seek( off_t offset );
-  INLINE off_t tell() const; // returns the current offset or -1 if !open
-  INLINE off_t size() const;
+  off_t tell() const; // returns the current offset or -1 if !open
+  off_t size() const;
   const char* lastError() const;
   const char* filename() const;
 
