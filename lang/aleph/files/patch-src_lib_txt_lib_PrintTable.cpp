
$FreeBSD$

--- src/lib/txt/lib/PrintTable.cpp.orig	Sun Aug 22 21:13:07 2004
+++ src/lib/txt/lib/PrintTable.cpp	Sun Aug 22 21:13:50 2004
@@ -85,7 +85,7 @@
     d_cols = 1;
     d_rows = 0;
     // initialize the data table
-    p_data = new (String*)[d_size];
+    p_data = new String*[d_size];
     for (long i = 0; i < d_size; i++) p_data[i] = nilp;
     // initialize the format size and column width
     p_csiz = new long [d_cols];
@@ -107,7 +107,7 @@
     d_cols = cols;
     d_rows = 0;
     // initialize the data table
-    p_data = new (String*)[d_size];
+    p_data = new String*[d_size];
     for (long i = 0; i < d_size; i++) p_data[i] = nilp;
     // initialize the format size and column width
     p_csiz = new long [d_cols];
@@ -129,7 +129,7 @@
     d_cols = cols;
     d_rows = 0;
     // initialize the data table
-    p_data = new (String*)[d_size];
+    p_data = new String*[d_size];
     for (long i = 0; i < d_size; i++) p_data[i] = nilp;
     // initialize the format size and column width
     p_csiz = new long [d_cols];
@@ -362,7 +362,7 @@
       return;
     }
     // create a new table
-    String** data = new (String*) [size];
+    String** data = new String* [size];
     for (long i = 0;      i < d_rows; i++) data[i] = p_data[i];
     for (long i = d_rows; i < size;   i++) data[i] = nilp;
     // update table and remove old one
