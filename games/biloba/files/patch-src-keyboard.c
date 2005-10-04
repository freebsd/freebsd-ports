--- src/keyboard.c.orig	Fri Sep 23 15:45:22 2005
+++ src/keyboard.c	Mon Oct  3 03:52:28 2005
@@ -60,8 +60,8 @@
 	int mcode = 0;
 	SDL_LockMutex(keyb_mutex);
 	if (event_list) {
-		mcode = (int)event_list->data;
 		LList *next = event_list->next;
+		mcode = (int)event_list->data;
 		free(event_list);
 		event_list = next;
 #ifdef DEBUG
