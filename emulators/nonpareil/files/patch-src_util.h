--- src/util.h.orig	2008-08-24 00:37:18 UTC
+++ src/util.h
@@ -56,7 +56,7 @@ void realloc_strcpy (char **dest, char *
 // strlcpy will copy as much of src into dest as it can, up to one less than
 // the maximum length of dest specified by the argument l.  Unlike strncpy(),
 // strlcpy() will always leave dest NULL-terminated on return.
-char *strlcpy (char *dest, const char *src, size_t l);
+//char *strlcpy (char *dest, const char *src, size_t l);
 
 
 // strlncpy will copy up to n characters from src to dest, but not more than
