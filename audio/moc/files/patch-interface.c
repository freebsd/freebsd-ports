--- interface.c.orig	Thu Dec 29 15:06:55 2005
+++ interface.c	Tue Jan 10 16:15:06 2006
@@ -2948,6 +2948,8 @@
 
 	enum key_cmd cmd;
 
+	int selected;
+
 	/* in this entry, we also operate on the menu */
 	if ((cmd = get_key_cmd(CON_ENTRY, ch)) == KEY_CMD_WRONG)
 		cmd = get_key_cmd(CON_MENU, ch);
@@ -3003,7 +3005,7 @@
 		
 		if (ch == '\n' && entry.text[0] && menu_nitems(curr_menu))
 			go_file ();
-		int selected = menu_curritem(curr_menu);
+		selected = menu_curritem(curr_menu);
 		if ((selected < 0 && old_curr_menu) ||
 			(curr_menu->nitems<=selected && old_curr_menu) || 
 			(old_curr_menu && (menu_item_get_type(curr_menu, selected))!=F_DIR)) 
