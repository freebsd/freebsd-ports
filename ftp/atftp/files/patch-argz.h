--- argz.h.orig	2010-10-04 18:31:14.000000000 +0800
+++ argz.h	2010-10-04 18:32:03.000000000 +0800
@@ -38,7 +38,9 @@
 #ifndef _ARGZ_H
 #define _ARGZ_H	1
 
+#ifdef HAVE_FEATURES_H
 #include <features.h>
+#endif
 
 #define __need_error_t
 #include <errno.h>
@@ -55,109 +57,28 @@
 
 __BEGIN_DECLS
 
-/* Make a '\0' separated arg vector from a unix argv vector, returning it in
-   ARGZ, and the total length in LEN.  If a memory allocation error occurs,
-   ENOMEM is returned, otherwise 0.  The result can be destroyed using free. */
-extern error_t __argz_create (char *__const __argv[], char **__restrict __argz,
-			      size_t *__restrict __len) __THROW;
-extern error_t argz_create (char *__const __argv[], char **__restrict __argz,
-			    size_t *__restrict __len) __THROW;
-
 /* Make a '\0' separated arg vector from a SEP separated list in
    STRING, returning it in ARGZ, and the total length in LEN.  If a
    memory allocation error occurs, ENOMEM is returned, otherwise 0.
    The result can be destroyed using free.  */
 extern error_t __argz_create_sep (__const char *__restrict __string,
 				  int __sep, char **__restrict __argz,
-				  size_t *__restrict __len) __THROW;
+				  size_t *__restrict __len);
 extern error_t argz_create_sep (__const char *__restrict __string,
 				int __sep, char **__restrict __argz,
-				size_t *__restrict __len) __THROW;
+				size_t *__restrict __len);
 
 /* Returns the number of strings in ARGZ.  */
-extern size_t __argz_count (__const char *__argz, size_t __len)
-     __THROW __attribute_pure__;
-extern size_t argz_count (__const char *__argz, size_t __len)
-     __THROW __attribute_pure__;
+extern size_t __argz_count (__const char *__argz, size_t __len);
+extern size_t argz_count (__const char *__argz, size_t __len);
 
 /* Puts pointers to each string in ARGZ into ARGV, which must be large enough
    to hold them all.  */
 extern void __argz_extract (__const char *__restrict __argz, size_t __len,
-			    char **__restrict __argv) __THROW;
+			    char **__restrict __argv);
 extern void argz_extract (__const char *__restrict __argz, size_t __len,
-			  char **__restrict __argv) __THROW;
+			  char **__restrict __argv);
 
-/* Make '\0' separated arg vector ARGZ printable by converting all the '\0's
-   except the last into the character SEP.  */
-extern void __argz_stringify (char *__argz, size_t __len, int __sep) __THROW;
-extern void argz_stringify (char *__argz, size_t __len, int __sep) __THROW;
-
-/* Append BUF, of length BUF_LEN to the argz vector in ARGZ & ARGZ_LEN.  */
-extern error_t __argz_append (char **__restrict __argz,
-			      size_t *__restrict __argz_len,
-			      __const char *__restrict __buf, size_t _buf_len)
-     __THROW;
-extern error_t argz_append (char **__restrict __argz,
-			    size_t *__restrict __argz_len,
-			    __const char *__restrict __buf, size_t __buf_len)
-     __THROW;
-
-/* Append STR to the argz vector in ARGZ & ARGZ_LEN.  */
-extern error_t __argz_add (char **__restrict __argz,
-			   size_t *__restrict __argz_len,
-			   __const char *__restrict __str) __THROW;
-extern error_t argz_add (char **__restrict __argz,
-			 size_t *__restrict __argz_len,
-			 __const char *__restrict __str) __THROW;
-
-/* Append SEP separated list in STRING to the argz vector in ARGZ &
-   ARGZ_LEN.  */
-extern error_t __argz_add_sep (char **__restrict __argz,
-			       size_t *__restrict __argz_len,
-			       __const char *__restrict __string, int __delim)
-     __THROW;
-extern error_t argz_add_sep (char **__restrict __argz,
-			     size_t *__restrict __argz_len,
-			     __const char *__restrict __string, int __delim)
-     __THROW;
-
-/* Delete ENTRY from ARGZ & ARGZ_LEN, if it appears there.  */
-extern void __argz_delete (char **__restrict __argz,
-			   size_t *__restrict __argz_len,
-			   char *__restrict __entry) __THROW;
-extern void argz_delete (char **__restrict __argz,
-			 size_t *__restrict __argz_len,
-			 char *__restrict __entry) __THROW;
-
-/* Insert ENTRY into ARGZ & ARGZ_LEN before BEFORE, which should be an
-   existing entry in ARGZ; if BEFORE is NULL, ENTRY is appended to the end.
-   Since ARGZ's first entry is the same as ARGZ, argz_insert (ARGZ, ARGZ_LEN,
-   ARGZ, ENTRY) will insert ENTRY at the beginning of ARGZ.  If BEFORE is not
-   in ARGZ, EINVAL is returned, else if memory can't be allocated for the new
-   ARGZ, ENOMEM is returned, else 0.  */
-extern error_t __argz_insert (char **__restrict __argz,
-			      size_t *__restrict __argz_len,
-			      char *__restrict __before,
-			      __const char *__restrict __entry) __THROW;
-extern error_t argz_insert (char **__restrict __argz,
-			    size_t *__restrict __argz_len,
-			    char *__restrict __before,
-			    __const char *__restrict __entry) __THROW;
-
-/* Replace any occurrences of the string STR in ARGZ with WITH, reallocating
-   ARGZ as necessary.  If REPLACE_COUNT is non-zero, *REPLACE_COUNT will be
-   incremented by number of replacements performed.  */
-extern error_t __argz_replace (char **__restrict __argz,
-			       size_t *__restrict __argz_len,
-			       __const char *__restrict __str,
-			       __const char *__restrict __with,
-			       unsigned int *__restrict __replace_count);
-extern error_t argz_replace (char **__restrict __argz,
-			     size_t *__restrict __argz_len,
-			     __const char *__restrict __str,
-			     __const char *__restrict __with,
-			     unsigned int *__restrict __replace_count);
-
 /* Returns the next entry in ARGZ & ARGZ_LEN after ENTRY, or NULL if there
    are no more.  If entry is NULL, then the first entry is returned.  This
    behavior allows two convenient iteration styles:
@@ -173,14 +94,14 @@
       ...;
 */
 extern char *__argz_next (__const char *__restrict __argz, size_t __argz_len,
-			  __const char *__restrict __entry) __THROW;
+			  __const char *__restrict __entry);
 extern char *argz_next (__const char *__restrict __argz, size_t __argz_len,
-			__const char *__restrict __entry) __THROW;
+			__const char *__restrict __entry);
 
 #ifdef __USE_EXTERN_INLINES
 extern inline char *
 __argz_next (__const char *__argz, size_t __argz_len,
-	     __const char *__entry) __THROW
+	     __const char *__entry)
 {
   if (__entry)
     {
@@ -194,7 +115,7 @@
 }
 extern inline char *
 argz_next (__const char *__argz, size_t __argz_len,
-	   __const char *__entry) __THROW
+	   __const char *__entry)
 {
   return __argz_next (__argz, __argz_len, __entry);
 }
