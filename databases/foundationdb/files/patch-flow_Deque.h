--- flow/Deque.h.orig	2019-04-09 00:11:05 UTC
+++ flow/Deque.h
@@ -168,7 +168,7 @@ class Deque { (private)
 			new (&newArr[i - begin]) T(std::move(arr[i&mask]));
 			arr[i&mask].~T();
 		}
-		aligned_free(arr);
+		free(arr);
 		arr = newArr;
 		end -= begin;
 		begin = 0;
@@ -179,7 +179,7 @@ class Deque { (private)
 		for (int i = begin; i != end; i++)
 			arr[i&mask].~T();
 		if(arr)
-			aligned_free(arr);
+			free(arr);
 	}
 };
 
