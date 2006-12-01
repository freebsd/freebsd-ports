--- numerical/matrixMat.cpp.orig	Mon May 13 14:07:45 2002
+++ numerical/matrixMat.cpp	Thu Nov 30 23:54:37 2006
@@ -48,9 +48,9 @@
 template <class T>
 LUMatrix<T>& LUMatrix<T>::operator=(const LUMatrix<T>& a){
   resize(a.rows(),a.cols()) ;
-  for(int i=0;i<rows();++i)
-    for(int j=0;j<cols();++j)
-      elem(i,j) = a(i,j) ;
+  for(int i=0;i<this->rows();++i)
+    for(int j=0;j<this->cols();++j)
+      this->elem(i,j) = a(i,j) ;
   pivot_ = a.pivot_ ;
   return *this ;
 }
@@ -90,7 +90,7 @@
   //	lu = a;	 must do it by copying or LUFACT will be recursively called !
   for(i=0;i<n;++i)
     for(j=0;j<n;++j)
-      elem(i,j) = a(i,j) ;
+      this->elem(i,j) = a(i,j) ;
 
   errval = 0;
   nm1 = n - 1;
@@ -129,24 +129,24 @@
 	    }
 	  pivot_[k] = l;
 
-	  if ( elem(l,k) != 0.0 )
+	  if ( this->elem(l,k) != 0.0 )
 	    {			// nonsingular pivot found 
 	      if (l != k ){	// interchange needed 
 		for (i = k; i < n; i++)
 		  {
-		    t = elem(l,i) ;
-		    elem(l,i) = elem(k,i) ;
-		    elem(k,i) = t ; 
+		    t = this->elem(l,i) ;
+		    this->elem(l,i) = this->elem(k,i) ;
+		    this->elem(k,i) = t ; 
 		  }
 		sign = -sign ;
 	      }
-	      q =  elem(k,k);	/* scale row */
+	      q =  this->elem(k,k);	/* scale row */
 	      for (i = kp1; i < n; i++)
 		{
-		  t = - elem(i,k)/q;
-		  elem(i,k) = t;
+		  t = - this->elem(i,k)/q;
+		  this->elem(i,k) = t;
 		  for (j = kp1; j < n; j++)
-		    elem(i,j) += t * elem(k,j);
+		    this->elem(i,j) += t * this->elem(k,j);
 		}
 	    }
 	  else		/* pivot singular */
@@ -156,7 +156,7 @@
     }
   
   pivot_[nm1] = nm1;
-  if (elem(nm1,nm1) == 0.0)
+  if (this->elem(nm1,nm1) == 0.0)
     errval = nm1;  
   return *this;
 }
@@ -196,9 +196,9 @@
 */
 template <class T>
 T LUMatrix<T>::determinant(){
-  T det = elem(0,0) ;
-  for(int i=1;i<rows();++i)
-    det *= elem(i,i) ;
+  T det = this->elem(0,0) ;
+  for(int i=1;i<this->rows();++i)
+    det *= this->elem(i,i) ;
   return det * (T)sign ;
 }
 
@@ -253,18 +253,18 @@
   T ten;
   int i, j, k, l, kb, kp1, nm1, n, coln;
 
-  if ( rows() != cols() )
+  if ( this->rows() != this->cols() )
     {
 #ifdef USE_EXCEPTION
-    throw WrongSize2D(rows(),cols(),0,0) ;
+    throw WrongSize2D(this->rows(),this->cols(),0,0) ;
 #else
       Error error("invm");
-      error << "matrix inverse, not square: " << rows() << " by " << cols() << endl;
+      error << "matrix inverse, not square: " << this->rows() << " by " << this->cols() << endl;
       error.fatal();
 #endif
     }
 
-  n = coln = rows();
+  n = coln = this->rows();
 
 
   inv = *this ;
@@ -338,13 +338,13 @@
 template <class T>
 Matrix<T> LUMatrix<T>::inverse() 
 {
-  if ( rows() != cols() )
+  if ( this->rows() != this->cols() )
     {
 #ifdef USE_EXCEPTION
-      throw WrongSize2D(rows(),cols(),0,0) ;
+      throw WrongSize2D(this->rows(),this->cols(),0,0) ;
 #else
       Error error("invm");
-      error << "matrix inverse, not square: " << rows() << " by " << cols() << endl;
+      error << "matrix inverse, not square: " << this->rows() << " by " << this->cols() << endl;
       error.fatal();
 #endif
     }
