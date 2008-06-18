Index: ptr.c
@@ -407,6 +407,7 @@
     return (char*)p; /* shortcut for NULL */
 }
 
+#ifdef _GNU_SOURCE
 /*
  * find last occurrence of c in p
  * return NULL if none found.
@@ -427,6 +428,7 @@
     else
 	return NULL;
 }
+#endif
 
 char *ptrrchr __P2 (ptr,p, char,c)
 {
