--- runtime.c.orig
+++ runtime.c
@@ -1612,7 +1612,7 @@
   p0 = p;
   *(p++) = C_FLONUM_TYPE | sizeof(double);
   *((double *)p) = n;
-  *ptr = p + 2;
+  *ptr = (C_word *)((C_word)p + sizeof(double));
   return (C_word)p0;
 }
 
