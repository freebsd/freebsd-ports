--- src/boards/click_on_letter.c.orig	Tue Nov 30 04:04:02 2004
+++ src/boards/click_on_letter.c	Tue Nov 30 04:14:48 2004
@@ -275,21 +275,20 @@
 static GnomeCanvasItem *click_on_letter_create_item(GnomeCanvasGroup *parent)
 {
 
-  int xOffset,yOffset,i,j;
+  int xOffset,yOffset,i,j,length_of_aphabet,numbers[number_of_letters];
   GdkPixbuf *button_pixmap = NULL;
+  gchar *letters[number_of_letters];
 
   /* TRANSLATORS: Put here the alphabet in your language */
   gchar *alphabet=_("abcdefghijklmnopqrstuvwxyz");
   assert(g_utf8_validate(alphabet,-1,NULL)); // require by all utf8-functions
 
 
-  int length_of_aphabet=g_utf8_strlen (alphabet,-1);
+  length_of_aphabet=g_utf8_strlen (alphabet,-1);
 
   number_of_letters=gcomprisBoard->level+1;
   if (number_of_letters>MAX_NUMBER_OF_LETTERS) number_of_letters=MAX_NUMBER_OF_LETTERS;
 
-  int numbers[number_of_letters];
-  gchar *letters[number_of_letters];
   assert(number_of_letters<=length_of_aphabet); // because we must set unique letter on every "vagon"
 
   for (i=0;i<number_of_letters;i++){
