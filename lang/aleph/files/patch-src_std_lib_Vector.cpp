
$FreeBSD$

--- src/std/lib/Vector.cpp.orig	Sun Aug 22 21:10:59 2004
+++ src/std/lib/Vector.cpp	Sun Aug 22 21:11:43 2004
@@ -56,7 +56,7 @@
     if (size < 0) throw Exception ("size-error","in vector constructor");
     d_size   = size;
     d_length = 0;
-    p_vector = new (Object*)[d_size];
+    p_vector = new Object*[d_size];
     for (long i = 0; i < d_size; i++) p_vector[i] = nilp;
   }
   
@@ -65,7 +65,7 @@
   Vector::Vector (const Vector& that) {
     d_size   = that.d_size;
     d_length = that.d_length;
-    p_vector = new (Object*)[d_size];
+    p_vector = new Object*[d_size];
     for (long i = 0; i < d_length; i++)
       p_vector[i] = Object::iref (that.p_vector[i]);
   }
@@ -100,7 +100,7 @@
     // copy old to new
     d_size   = that.d_size;
     d_length = that.d_length;
-    p_vector = new (Object*)[d_size];
+    p_vector = new Object*[d_size];
     for (long i = 0; i < d_length; i++)
     p_vector[i] = Object::iref (that.p_vector[i]);
     return *this;
@@ -170,7 +170,7 @@
       // check if we have to resize the vector
       if (d_length >= d_size) {
 	long size = (d_size <= 0) ? 1 : d_size * 2;
-	Object** vector = new (Object*)[size];
+	Object** vector = new Object*[size];
 	for (long i = 0; i < d_length; i++)
 	  vector[i] = p_vector[i];
 	delete [] p_vector;
