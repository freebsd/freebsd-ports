clang build fix. It complained about using a function declaration as the object
for the placement new call.
--- libcult/cult/mm/static-ptr.hxx~	2012-08-06 19:57:49.000000000 -0300
+++ libcult/cult/mm/static-ptr.hxx	2012-08-06 19:58:19.000000000 -0300
@@ -60,7 +60,8 @@
       static X*
       instance_ ()
       {
-        static X* i = new (KeyList ()) X;
+        KeyList k;
+        static X* i = new (k) X;
         return i;
       }
 
