--- src/nnet/map.h.orig
+++ src/nnet/map.h
@@ -25,7 +25,7 @@
 	else {
 		TData x;
 		x.first() = key;
-		return insert (x)->second();
+		return this->insert (x)->second();
 	}
 }
 
