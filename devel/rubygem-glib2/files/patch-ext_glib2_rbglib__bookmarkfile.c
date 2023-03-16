--- ext/glib2/rbglib_bookmarkfile.c.orig	2023-03-16 13:19:47 UTC
+++ ext/glib2/rbglib_bookmarkfile.c
@@ -35,6 +35,7 @@ bookmarkfile_copy(const GBookmarkFile* file)
     return (GBookmarkFile*)file;
 }
 
+#if !GLIB_CHECK_VERSION(2, 76, 0)
 static GType
 g_bookmark_file_get_type(void)
 {
@@ -48,6 +49,7 @@ g_bookmark_file_get_type(void)
 /************************************************/
 
 #define G_TYPE_BOOKMARK_FILE (g_bookmark_file_get_type())
+#endif
 
 #define RG_TARGET_NAMESPACE cBookmarkFile
 #define _SELF(self) ((GBookmarkFile*)(RVAL2BOXED(self, G_TYPE_BOOKMARK_FILE)))
