--- gio/xdgmime/xdgmimecache.h.orig	2007-09-13 16:35:37.000000000 -0400
+++ gio/xdgmime/xdgmimecache.h	2007-09-14 00:59:43.000000000 -0400
@@ -42,6 +42,9 @@ typedef struct _XdgMimeCache XdgMimeCach
 #define _xdg_mime_cache_list_mime_parents             XDG_ENTRY(cache_list_mime_parents)
 #define _xdg_mime_cache_mime_type_subclass            XDG_ENTRY(cache_mime_type_subclass)
 #define _xdg_mime_cache_unalias_mime_type             XDG_ENTRY(cache_unalias_mime_type)
+#define _xdg_mime_cache_is_valid_mime_type            XDG_ENTRY(cache_is_valid_mime_type)
+#define _xdg_mime_cache_mime_type_equal               XDG_ENTRY(cache_mime_type_equal)
+#define _xdg_mime_cache_media_type_equal              XDG_ENTRY(cache_media_type_equal)
 
 #endif
 
