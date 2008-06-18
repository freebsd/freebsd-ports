Index: ptr.h
@@ -65,7 +65,7 @@
 /* TODO: watch memrchr, it is defined differently here than under _GNU_SOURCE,
  * so it could cause bizarre results if a module makes use of a library that
  * uses it */
-char *memrchr   __P ((char *p, int lenp, char c));
+//char *memrchr   __P ((char *p, int lenp, char c));
 #endif
 
 #endif /* _PTR_H_ */
