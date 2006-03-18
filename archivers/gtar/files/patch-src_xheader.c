
$FreeBSD$

--- src/xheader.c.orig
+++ src/xheader.c
@@ -32,6 +32,10 @@
 
 #include <fnmatch.h>
 
+#ifndef SIZE_MAX
+# define SIZE_MAX ((size_t) -1)
+#endif
+
 static bool xheader_protected_pattern_p (char const *pattern);
 static bool xheader_protected_keyword_p (char const *keyword);
 static void xheader_set_single_keyword (char *) __attribute__ ((noreturn));
@@ -783,6 +787,32 @@
   xheader_print (xhdr, keyword, sbuf);
 }
 
+static bool
+decode_num (uintmax_t *num, char const *arg, uintmax_t maxval,
+        char const *keyword)
+{
+  uintmax_t u;
+  char *arg_lim;
+
+  if (! (ISDIGIT (*arg)
+     && (errno = 0, u = strtoumax (arg, &arg_lim, 10), !*arg_lim)))
+    {
+      ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
+          keyword, arg));
+      return false;
+    }
+
+  if (! (u <= maxval && errno != ERANGE))
+    {
+      ERROR ((0, 0, _("Extended header %s=%s is out of range"),
+        keyword, arg));
+      return false;
+    }
+
+  *num = u;
+  return true;
+}
+
 static void
 dummy_coder (struct tar_stat_info const *st __attribute__ ((unused)),
 	     char const *keyword __attribute__ ((unused)),
@@ -821,7 +851,7 @@
 gid_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, TYPE_MAXIMUM (gid_t), "gid"))
     st->stat.st_gid = u;
 }
 
@@ -903,7 +933,7 @@
 size_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, TYPE_MAXIMUM (off_t), "size"))
     st->archive_file_size = st->stat.st_size = u;
 }
 
@@ -918,7 +948,7 @@
 uid_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, TYPE_MAXIMUM (uid_t), "uid"))
     st->stat.st_uid = u;
 }
 
@@ -946,7 +976,7 @@
 sparse_size_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, TYPE_MAXIMUM (off_t), "GNU.sparse.size"))
     st->stat.st_size = u;
 }
 
@@ -962,10 +992,10 @@
 sparse_numblocks_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, SIZE_MAX, "GNU.sparse.numblocks"))
     {
       st->sparse_map_size = u;
-      st->sparse_map = calloc(st->sparse_map_size, sizeof(st->sparse_map[0]));
+      st->sparse_map = xcalloc (u, sizeof st->sparse_map[0]);
       st->sparse_map_avail = 0;
     }
 }
@@ -982,8 +1012,14 @@
 sparse_offset_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, TYPE_MAXIMUM (off_t), "GNU.sparse.offset"))
+    {
+      if (st->sparse_map_avail < st->sparse_map_size)
     st->sparse_map[st->sparse_map_avail].offset = u;
+      else
+    ERROR ((0, 0, _("Malformed extended header: excess %s=%s"),
+        "GNU.sparse.offset", arg));
+    }
 }
 
 static void
@@ -998,15 +1034,13 @@
 sparse_numbytes_decoder (struct tar_stat_info *st, char const *arg)
 {
   uintmax_t u;
-  if (xstrtoumax (arg, NULL, 10, &u, "") == LONGINT_OK)
+  if (decode_num (&u, arg, SIZE_MAX, "GNU.sparse.numbytes"))
     {
       if (st->sparse_map_avail == st->sparse_map_size)
-	{
-	  st->sparse_map_size *= 2;
-	  st->sparse_map = xrealloc (st->sparse_map,
-				     st->sparse_map_size
-				     * sizeof st->sparse_map[0]);
-	}
+        st->sparse_map = x2nrealloc (st->sparse_map,
+                                    &st->sparse_map_size,
+                                    sizeof st->sparse_map[0]);
+
       st->sparse_map[st->sparse_map_avail++].numbytes = u;
     }
 }
