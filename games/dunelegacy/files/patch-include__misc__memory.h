--- ./include/misc/memory.h.orig	2011-07-15 23:19:01.000000000 +0000
+++ ./include/misc/memory.h	2014-08-15 18:13:48.594576019 +0000
@@ -1,12 +1,12 @@
 #ifndef MEMORY_INCLUDED
 #define MEMORY_INCLUDED
 
-#include <tr1/memory>
+#include <memory>
 
 namespace std {
-	using std::tr1::shared_ptr;
+	using std::shared_ptr;
 
-	using std::tr1::dynamic_pointer_cast;
+	using std::dynamic_pointer_cast;
 }
 
 #endif //MEMORY_INCLUDED
