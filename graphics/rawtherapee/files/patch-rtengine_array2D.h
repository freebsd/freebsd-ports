--- ./rtengine/array2D.h.orig	2012-01-31 05:00:05.000000000 +0400
+++ ./rtengine/array2D.h	2012-03-30 13:26:24.000000000 +0400
@@ -156,7 +156,7 @@
 	}
 
 	// use with indices
-	T * operator[](size_t index) {
+	T * operator[](int index) {
         assert(index<y); 
 		return ptr[index];
 	}
@@ -252,7 +252,7 @@
 
 public:
 	multi_array2D(int x, int y, int flags = 0) {
-		for (int i = 0; i < num; i++)
+		for (size_t i = 0; i < num; i++)
 			list[i](x, y, flags);
 	}
 
@@ -260,9 +260,9 @@
 		//printf("trying to delete the list of array2D objects\n");
 	}
 
-	array2D<T> & operator[](size_t index) {
-		if (index >= num) {
-			printf("index %zu is out of range[0..%zu]", index, num - 1);
+	array2D<T> & operator[](int index) {
+		if (static_cast<size_t>(index) >= num) {
+			printf("index %0u is out of range[0..%0u]", index, num - 1);
 			raise( SIGSEGV);
 		}
 		return list[index];
