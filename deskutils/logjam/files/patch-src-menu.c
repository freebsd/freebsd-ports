--- src/menu.c.orig	Mon Oct 24 00:11:08 2005
+++ src/menu.c	Thu Aug 17 02:01:02 2006
@@ -408,7 +408,7 @@
 	0, NULL },
 {    "/Insert/---",               NULL, NULL, 0, "<Separator>" },
 { N_("/Insert/_Link..."),         "<ctl>L",      menu_make_link },
-{ N_("/Insert/_Image..."),        NULL,          menu_insert_image },
+{ N_("/Insert/_Image..."),        "<ctl><alt>P", menu_insert_image },
 { N_("/Insert/_Journal Link..."), "<ctl><alt>L", menu_make_journal_link },
 { N_("/Insert/lj-_cut..."),       "<ctl><alt>X", menu_ljcut, 0, NULL },
