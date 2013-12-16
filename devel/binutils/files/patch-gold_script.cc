--- gold/script.cc.dist	2012-09-01 19:52:34.000000000 -0500
+++ gold/script.cc	2012-09-01 19:53:22.000000000 -0500
@@ -2534,8 +2534,6 @@
     fprintf(f, "      }\n");
 }
 
-} // End namespace gold.
-
 // The remaining functions are extern "C", so it's clearer to not put
 // them in namespace gold.
 
@@ -3391,3 +3389,5 @@
 
   return length;
 }
+
+} // End namespace gold.
