--- src/vc.c.orig	Mon May 16 13:33:11 2005
+++ src/vc.c	Mon May 16 13:33:11 2005
@@ -60,28 +60,23 @@
 inline void 
 blatch(void *head, int n)
 {
-
-    __asm__         volatile ("\t clc\n"
-			                      "1:\n"
-			                      "\t andb %%bl, (%%eax)\n"
-			                      "\t incl %%eax\n"
-			                      "\t loop 1b\n"
-			      :               "=bl" (head), "=c"(n)
-		      :               "eax"((long)head), "0"(0x7F), "1"(n));
+    char *tmp = (char *)head;
+    do {
+        *tmp &= 0x7f;
+        tmp++;
+    }  while(  --n  );
 }
 
 static
 inline void 
 llatch(void *head, int n)
 {
-
-    __asm__         volatile ("\t clc\n"
-			                      "1:\n"
-			                      "\t andl %%ebx, (%%eax)\n"
-			                      "\t addl $4, %%eax\n"
-			                      "\t loop 1b\n"
-			      :               "=ebx" (head), "=c"(n)
-	   :               "eax"((long)head), "0"(0x7F7F7F7F), "1"(n >> 2));
+    int *tmp = (int *)head;
+    n /= 4;
+    do {
+        *tmp &= 0x7f7f7f7f;
+        tmp++;
+    }  while(  --n  );
 }
 
 static inline u_int 
