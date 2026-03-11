--- document-portal/document-portal-fuse.c.orig	2025-05-20 17:07:14 UTC
+++ document-portal/document-portal-fuse.c
@@ -429,14 +429,18 @@ renameat2_flags_to_string (int flags)
 #if HAVE_RENAMEAT2
   GString *s = g_string_new ("");
 
+#ifdef RENAME_EXCHANGE
   if (flags & RENAME_EXCHANGE)
     g_string_append (s, "EXCHANGE,");
+#endif
 
   if (flags & RENAME_NOREPLACE)
     g_string_append (s, "NOREPLACE,");
 
+#ifdef RENAME_WHITEOUT
   if (flags & RENAME_WHITEOUT)
     g_string_append (s, "WHITEOUT,");
+#endif
 
   /* Remove last comma */
   if (s->len > 0)
