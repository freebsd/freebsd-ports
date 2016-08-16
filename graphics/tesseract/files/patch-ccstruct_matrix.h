--- ccstruct/matrix.h.orig	2016-08-11 18:32:41 UTC
+++ ccstruct/matrix.h
@@ -30,7 +30,7 @@
 
 class BLOB_CHOICE_LIST;
 
-#define NOT_CLASSIFIED reinterpret_cast<BLOB_CHOICE_LIST*>(NULL)
+#define NOT_CLASSIFIED reinterpret_cast<BLOB_CHOICE_LIST*>(0)
 
 // A generic class to hold a 2-D matrix with entries of type T, but can also
 // act as a base class for other implementations, such as a triangular or
