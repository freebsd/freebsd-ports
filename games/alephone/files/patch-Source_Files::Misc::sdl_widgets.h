--- Source_Files/Misc/sdl_widgets.h.orig	Mon Jul 16 21:37:51 2001
+++ Source_Files/Misc/sdl_widgets.h	Mon Sep 20 20:46:48 2004
@@ -402,7 +402,7 @@
 protected:
 	void draw_items(SDL_Surface *s) const
 	{
-		vector<T>::const_iterator i = items.begin() + top_item;
+		typename vector<T>::const_iterator i = items.begin() + top_item;
 		int x = rect.x + get_dialog_space(LIST_L_SPACE);
 		int y = rect.y + get_dialog_space(LIST_T_SPACE);
 		int width = rect.w - get_dialog_space(LIST_L_SPACE) - get_dialog_space(LIST_R_SPACE);
@@ -413,7 +413,7 @@
 	const vector<T> &items;	// List of items
 
 private:
-	virtual void draw_item(vector<T>::const_iterator i, SDL_Surface *s, int x, int y, int width, bool selected) const = 0;
+	virtual void draw_item(typename vector<T>::const_iterator i, SDL_Surface *s, int x, int y, int width, bool selected) const = 0;
 };
 
 #endif
