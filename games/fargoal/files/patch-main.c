--- main.c	Thu Jul 31 10:06:51 2003
+++ main.c	Mon Nov 17 09:51:26 2003
@@ -365,12 +365,8 @@
 
 	fix_alt_tab ();	
 
-	#if (ALLEGRO_SUB_VERSION == 0)
-		set_window_close_button (1);
-		set_window_close_hook (close_button);
-	#else
-		set_close_button_callback (close_button);
-	#endif
+	set_window_close_button (1);
+	set_window_close_hook (close_button);
 	
 	if (colordepth == 8)
 	{
