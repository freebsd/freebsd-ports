--- libgnomevfs/gnome-vfs-mime-magic.c.orig	Mon Mar 10 18:49:02 2003
+++ libgnomevfs/gnome-vfs-mime-magic.c	Mon Mar 10 18:49:06 2003
@@ -759,6 +759,9 @@
 	
  		if (g_utf8_get_char_validated(end, remaining_bytes) == -2)
 			return TRUE;
+		/* XXX This next section can't be used until FreeBSD gets a
+		 * working wchar.h and wctype.h. */
+#if 0
 		else {
 			size_t wlen;
 			wchar_t wc;
@@ -802,6 +805,7 @@
 			}
 			return TRUE;
 		}
+#endif
 	} 
 }
 
