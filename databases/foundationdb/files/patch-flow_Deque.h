--- flow/Deque.h.orig	2018-04-22 14:36:29 UTC
+++ flow/Deque.h
@@ -166,7 +166,7 @@ private:
 			new (&newArr[i - begin]) T(std::move(arr[i&mask]));
 			arr[i&mask].~T();
 		}
-		aligned_free(arr);
+		free(arr);
 		arr = newArr;
 		end -= begin;
 		begin = 0;
@@ -177,8 +177,8 @@ private:
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
