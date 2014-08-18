--- src/lib/mfb/mfbgnc.c.orig	2001-05-01 19:45:26.000000000 +0000
+++ src/lib/mfb/mfbgnc.c
@@ -120,7 +120,7 @@ char *PM;
     cp = PM;
     dp = result;
     if (cp == NULL) {
-        return;
+        return (NULL);
     }
     while (c = *cp++) {
         if(c == '$') {
@@ -300,7 +300,7 @@ char *PM;
                     y1 = reg;
                 }
                 else
-                    return;
+                    return (NULL);
                 hiy   = (y1 >> 7) & 037;
                 extra = x1 & 03 | ((y1 & 03) << 2);
                 loy   = (y1 >> 2) & 037;
@@ -427,7 +427,7 @@ char *PM;
             continue;
 
         default:
-            return;
+            return (NULL);
         }
     }
     *dp='\0';
