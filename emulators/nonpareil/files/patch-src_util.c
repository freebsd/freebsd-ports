--- src.orig/util.c    Mon Jul 24 14:32:21 2006
+++ src/util.c Mon Jul 24 14:34:48 2006
@@ -130,6 +130,7 @@
 }
 
 
+#if 0
 // strlcpy will copy as much of src into dest as it can, up to one less than
 // the maximum length of dest specified by the argument l.  Unlike strncpy(),
 // strlcpy() will always leave dest NULL-terminated on return.
@@ -139,6 +140,7 @@
   dest [l - 1] = '\0';
   return dest;
 }
+#endif
 
 
 // strlncpy will copy up to n characters from src to dest, but not more than
