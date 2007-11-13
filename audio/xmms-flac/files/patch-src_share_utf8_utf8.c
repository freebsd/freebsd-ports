
$FreeBSD$

--- src/share/utf8/utf8.c.orig
+++ src/share/utf8/utf8.c
@@ -28,6 +28,7 @@
 #include <config.h>
 #endif
 
+#include "share/alloc.h"
 #include "utf8.h"
 #include "charset.h"
 
@@ -57,10 +58,13 @@
         } else {
             size += 3;
         }
+        if(size+n < size) /* overflow check */
+            return NULL;
+        size += n;
         c = unicode[index++];
     }	
 
-    out = malloc(size + 1);
+    out = safe_malloc_add_2op_(size, /*+*/1);
     if (out == NULL)
         return NULL;
     index = 0;
@@ -101,11 +105,15 @@
         } else {
             index += 1;
         }
+        if(size + 1 == 0) /* overflow check */
+            return NULL;
         size += 1;
         c = utf8[index++];
     }	
 
-    out = malloc((size + 1) * sizeof(wchar_t));
+    if(size + 1 == 0) /* overflow check */
+        return NULL;
+    out = safe_malloc_mul_2op_((size + 1), /*times*/sizeof(wchar_t));
     if (out == NULL)
         return NULL;
     index = 0;
@@ -147,7 +155,7 @@
 		return -1;
 	}
 
-	unicode = calloc(wchars + 1, sizeof(unsigned short));
+	unicode = safe_calloc_(wchars + 1, sizeof(unsigned short));
 	if(unicode == NULL) 
 	{
 		fprintf(stderr, "Out of memory processing string to UTF8\n");
@@ -197,7 +205,7 @@
         return -1;
     }
 
-    *to = calloc(chars + 1, sizeof(unsigned char));
+    *to = safe_calloc_(chars + 1, sizeof(unsigned char));
     if(*to == NULL) 
     {
         fprintf(stderr, "Out of memory processing string to local charset\n");
@@ -285,7 +293,7 @@
   if (ret != -1)
     return ret;
 
-  s = malloc(fromlen + 1);
+  s = safe_malloc_add_2op_(fromlen, /*+*/1);
   if (!s)
     return -1;
   strcpy(s, from);
