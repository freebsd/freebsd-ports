--- inputs/hzinput.h.orig	Mon Nov 25 18:00:10 2002
+++ inputs/hzinput.h	Mon Nov 25 17:59:37 2002
@@ -86,7 +86,7 @@
 } hz_input_table;
 
 /************ private functions *******************/
-void InputAreaOutput(int x, u_char *string, int fg, int bg);
+/*void InputAreaOutput(int x, u_char *string, int fg, int bg);*/
 void FindMatchKey(void);
 void FillMatchChars(int j);
 void FillAssociateChars(int index);
