--- flow/Deque.h.orig	2019-01-09 22:28:32 UTC
+++ flow/Deque.h
@@ -166,7 +166,7 @@ class Deque { (private)
 			new (&newArr[i - begin]) T(std::move(arr[i&mask]));
 			arr[i&mask].~T();
 		}
-		aligned_free(arr);
+		free(arr);
 		arr = newArr;
 		end -= begin;
 		begin = 0;
@@ -177,8 +177,8 @@ class Deque { (private)
 		for (int i = begin; i != end; i++)
 			arr[i&mask].~T();
 		if(arr)
-			aligned_free(arr);
+			free(arr);
 	}
 };
 
-#endif
\ No newline at end of file
+#endif
