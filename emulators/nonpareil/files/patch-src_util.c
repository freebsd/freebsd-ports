--- src/util.c.orig	2008-08-24 00:37:18 UTC
+++ src/util.c
@@ -130,6 +130,7 @@ void realloc_strcpy (char **dest, char *
 }
 
 
+#if 0
 // strlcpy will copy as much of src into dest as it can, up to one less than
 // the maximum length of dest specified by the argument l.  Unlike strncpy(),
 // strlcpy() will always leave dest NULL-terminated on return.
@@ -139,6 +140,7 @@ char *strlcpy (char *dest, const char *s
   dest [l - 1] = '\0';
   return dest;
 }
+#endif
 
 
 // strlncpy will copy up to n characters from src to dest, but not more than
