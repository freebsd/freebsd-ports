--- libgnomevfs/xdgmime.h.orig	Sat Oct  7 10:42:32 2006
+++ libgnomevfs/xdgmime.h	Sat Oct  7 11:01:57 2006
@@ -52,11 +52,14 @@ typedef void (*XdgMimeDestroy)  (void *u
 #define xdg_mime_get_mime_type_from_file_name XDG_ENTRY(get_mime_type_from_file_name)
 #define xdg_mime_is_valid_mime_type           XDG_ENTRY(is_valid_mime_type)
 #define xdg_mime_mime_type_equal              XDG_ENTRY(mime_type_equal)
+#define _xdg_mime_mime_type_equal             XDG_ENTRY(mime_type_equal_p)
 #define xdg_mime_media_type_equal             XDG_ENTRY(media_type_equal)
 #define xdg_mime_mime_type_subclass           XDG_ENTRY(mime_type_subclass)
+#define _xdg_mime_mime_type_subclass          XDG_ENTRY(mime_type_subclass_p)
 #define xdg_mime_get_mime_parents             XDG_ENTRY(get_mime_parents)
 #define xdg_mime_list_mime_parents            XDG_ENTRY(list_mime_parents)
 #define xdg_mime_unalias_mime_type            XDG_ENTRY(unalias_mime_type)
+#define _xdg_mime_unalias_mime_type           XDG_ENTRY(unalias_mime_type_p)
 #define xdg_mime_get_max_buffer_extents       XDG_ENTRY(get_max_buffer_extents)
 #define xdg_mime_shutdown                     XDG_ENTRY(shutdown)
 #define xdg_mime_dump                         XDG_ENTRY(dump)
