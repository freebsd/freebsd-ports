--- src/importmusicxml.c.orig
+++ src/importmusicxml.c
@@ -392,7 +392,7 @@
     duration -= divisions/32;
     return get_rest_for_duration(ret, duration, divisions);
   } else if (duration==0)
-    return;
+    return -1;
 
   g_string_append(ret, "\n;Duration of rest not recognized\n");
 }
