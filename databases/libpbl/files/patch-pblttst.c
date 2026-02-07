--- pblhttst.c~	2011-05-26 11:28:13.000000000 +0200
+++ pblhttst.c	2011-05-26 11:28:49.000000000 +0200
@@ -139,8 +139,8 @@
                  data ? data : "NULL" );
         size = 0;
         data = pblHtCurrentKey( ht, &size );
-        fprintf( stdout, "pblHtCurrentKey( ht, &size ) data = %s, size %ld\n",
-                 data ? data : "NULL", size );
+        fprintf( stdout, "pblHtCurrentKey( ht, &size ) data = %s, size %lu\n",
+                 data ? data : "NULL", (unsigned long)size );
 
     }
 
