--- src/nnet/map.h.orig	2004-08-30 22:32:41 UTC
+++ src/nnet/map.h
@@ -25,7 +25,7 @@ T2 & TMap<T1,T2>::operator [] (const T1 
 	else {
 		TData x;
 		x.first() = key;
-		return insert (x)->second();
+		return this->insert (x)->second();
 	}
 }
 
