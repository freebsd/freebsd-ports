diff -urN ./include/defs.h.orig ./include/defs.h
--- ./include/defs.h.orig	Sun Jan 11 12:41:21 2004
+++ ./include/defs.h		Tue Dec 14 08:53:19 2004
@@ -57,49 +57,67 @@
 
 static inline void bzero2(void *head, int n)
 {
+    unsigned char *p = (unsigned char *) head;
+
 	while (n-- > 0)
-		*((unsigned char *)head)++ = (unsigned char)0x0;
+		*p++ = (unsigned char)0x0;
 }
 
 static inline void wzero(void *head, int n)
 {
+    unsigned short *p = (unsigned short *) head;
+
 	n >>= 1;
 	while (n-- > 0)
-		*((unsigned short *)head)++ = (unsigned short)0x0;
+		*p++ = (unsigned short)0x0;
 
 }
 
 static inline void lzero(void *head, int n)
 {
+    unsigned int *p = (unsigned int *) head;
+
 	n >>= 2;
     while (n-- > 0)
-        *((unsigned int *)head)++ = (unsigned int)0x0;
+        *p++ = (unsigned int)0x0;
 }
 
 static inline void bmove(void *dst, void *src, int n)
 {
+    unsigned char *d = (unsigned char *) dst;
+    unsigned char *s = (unsigned char *) src;
+
 	while(n-- > 0)
-		*((unsigned char *)dst)++ = *((unsigned char *)src)++;
+		*d++ = *s++;
 }
 
 static inline void brmove(void *dst, void *src, int n)
 {
+    unsigned char *d = (unsigned char *) dst;
+    unsigned char *s = (unsigned char *) src;
+
     while(n-- > 0)
-        *--((unsigned char *)dst) = *--((unsigned char *)src);
+        *--d = *--s;
 }
 
 static inline void wmove(void *dst, void *src, int n)
 {
+    unsigned short *d = (unsigned short *) dst;
+    unsigned short *s = (unsigned short *) src;
+
 	n >>= 1;
     while(n-- > 0)
-        *((unsigned short *)dst)++ = *((unsigned short *)src)++;
+        *d++ = *s++;
 }
 
 static inline void lmove(void *dst, void *src, int n)
 {
+    unsigned int *d = (unsigned int *) dst;
+    unsigned int *s = (unsigned int *) src;
+
 	n >>= 2;
 	while(n-- > 0)
-		*((unsigned int *)dst)++ = *((unsigned int *)src)++;
+		*d++ = *s++;
 }
 
 static inline void SafeFree(void **p)
