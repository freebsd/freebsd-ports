--- src.orig/util.h    Mon Jul 24 14:32:21 2006
+++ src/util.h Mon Jul 24 14:33:52 2006
@@ -56,7 +56,7 @@
 // strlcpy will copy as much of src into dest as it can, up to one less than
 // the maximum length of dest specified by the argument l.  Unlike strncpy(),
 // strlcpy() will always leave dest NULL-terminated on return.
-char *strlcpy (char *dest, const char *src, size_t l);
+//char *strlcpy (char *dest, const char *src, size_t l);
 
 
 // strlncpy will copy up to n characters from src to dest, but not more than
