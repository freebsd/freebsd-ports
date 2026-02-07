--- matrix/matrix.h.orig
+++ matrix/matrix.h
@@ -75,7 +75,7 @@
       
       Matrix<T>&	operator=(const Matrix<T>&);	
       T operator=(const T v) 
-	{ reset((T)0); 
+	{ this->reset((T)0); 
 	diag(v);
 	return v; }
       void submatrix(int i, int j, Matrix<T>&); 
