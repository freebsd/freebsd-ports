--- buttonlist.h.orig	Wed Jan 26 01:41:32 2000
+++ buttonlist.h	Sun Aug 22 19:24:13 2004
@@ -16,7 +16,7 @@
 
 	void Add_Button(Uint16 x, Uint16 y, Uint16 width, Uint16 height, 
 						void (*callback)(void)) {
-		struct button *belem;
+		button *belem;
 		
 		for ( belem=&button_list; belem->next; belem=belem->next );
 		belem->next = new button;
@@ -30,7 +30,7 @@
 	}
 
 	void Activate_Button(Uint16 x, Uint16 y) {
-		struct button *belem;
+		button *belem;
 
 		for ( belem=button_list.next; belem; belem=belem->next ) {
 			if ( (x >= belem->x1) && (x <= belem->x2) &&
@@ -42,7 +42,7 @@
 	}
 
 	void Delete_Buttons(void) {
-		struct button *belem, *btemp;
+		button *belem, *btemp;
 
 		for ( belem=button_list.next; belem; ) {
 			btemp = belem;
