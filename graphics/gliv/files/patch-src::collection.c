--- src/collection.c.orig	Thu Jul 29 06:40:56 2004
+++ src/collection.c	Thu Sep 30 20:46:04 2004
@@ -77,6 +77,7 @@
  * are '\0' terminated strings representing decimal numbers.
  */
 
+#include <sys/types.h>
 #include <sys/mman.h>           /* mmap(), PROT_READ, MAP_PRIVATE, ... */
 #include <stdio.h>              /* FILE, fopen(), fread(), fwrite(), ... */
 #include <string.h>             /* strlen(), strrchr() */
@@ -638,8 +639,8 @@
             guchar *base;
             guchar *ptr;
             guchar *end;
-        };
-    };
+        } s;
+    } u;
 };
 
 static void free_buffer(struct coll_src *source, guchar * buffer)
@@ -655,16 +656,16 @@
 
     if (source->is_file) {
         data = g_new(guchar, length);
-        if (fread(data, 1, length, source->file) != length) {
+        if (fread(data, 1, length, source->u.file) != length) {
             g_free(data);
             return NULL;
         }
     } else {
-        if (source->ptr + length > source->end)
+        if (source->u.s.ptr + length > source->u.s.end)
             return NULL;
 
-        data = source->ptr;
-        source->ptr += length;
+        data = source->u.s.ptr;
+        source->u.s.ptr += length;
     }
 
     if (is_string && data[length - 1] != '\0') {
@@ -678,12 +679,12 @@
 static gint read_char(struct coll_src *source)
 {
     if (source->is_file)
-        return fgetc(source->file);
+        return fgetc(source->u.file);
 
-    if (source->ptr >= source->end)
+    if (source->u.s.ptr >= source->u.s.end)
         return EOF;
 
-    return *(source->ptr++);
+    return *(source->u.s.ptr++);
 }
 
 static GdkPixbufDestroyNotify destroy_func(struct coll_src *source)
@@ -855,22 +856,22 @@
         goto no_mmap;
     }
 
-    source->base = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fileno(file), 0);
-    if (source->base == MAP_FAILED) {
+    source->u.s.base = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fileno(file), 0);
+    if (source->u.s.base == MAP_FAILED) {
         perror("mmap");
         goto no_mmap;
     }
 
     source->is_file = FALSE;
-    source->ptr = source->base;
-    source->end = source->base + length;
+    source->u.s.ptr = source->u.s.base;
+    source->u.s.end = source->u.s.base + length;
     goto ok;
 
   no_mmap:
     fseeko(file, 0, SEEK_SET);
 
     source->is_file = TRUE;
-    source->file = file;
+    source->u.file = file;
 
   ok:
     return source;
@@ -879,7 +880,7 @@
 static void destroy_source(struct coll_src *source, gboolean ok)
 {
     if (ok == FALSE && source->is_file == FALSE)
-        if (munmap(source->base, source->end - source->base) < 0)
+        if (munmap(source->u.s.base, source->u.s.end - source->u.s.base) < 0)
             perror("munmap");
 }
 
