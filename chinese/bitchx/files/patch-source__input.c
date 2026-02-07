--- source/input.c~	Tue Aug  5 20:43:47 2003
+++ source/input.c	Tue Aug  5 20:43:49 2003
@@ -94,6 +94,7 @@
 #define MIN_CHAR 		INPUT_BUFFER[MIN_POS]
 #define PREV_CHAR 		INPUT_BUFFER[THIS_POS-1]
 #define NEXT_CHAR 		INPUT_BUFFER[THIS_POS+1]
+#define	NTH_CHAR(offset)	INPUT_BUFFER[THIS_POS+(offset)]
 #define ADD_TO_INPUT(x) 	strmcat(INPUT_BUFFER, (x), INPUT_BUFFER_SIZE);
 #define INPUT_ONSCREEN 		current_screen->input_visible
 #define INPUT_VISIBLE 		INPUT_BUFFER[INPUT_ONSCREEN]
@@ -107,7 +108,11 @@
 
 
 #define HOLDLAST		current_screen->current_window->screen_hold
-  
+
+#define MY_ROLE_ENG 0
+#define MY_ROLE_HI  1
+#define MY_ROLE_LO  2
+
 Display *get_screen_hold(Window *win)
 {
 	return win->screen_hold;
@@ -124,6 +129,24 @@
 	return i;
 }
 
+static int check_my_role (int my_pos)
+{
+  int i = MIN_POS;
+  while (i <= my_pos) {
+    if ( is_big5_hi( INPUT_BUFFER[i] ) ) {
+      if ( i+1 <= my_pos ) {
+	if (is_big5( INPUT_BUFFER[i],INPUT_BUFFER[i+1]) ){
+	  if (i+1 == my_pos) return MY_ROLE_LO;
+	  else i+=1;
+	}
+      }
+      else return MY_ROLE_HI;
+    }
+    i+=1;
+  }
+  return MY_ROLE_ENG;
+}
+
 /* cursor_to_input: move the cursor to the input line, if not there already */
 extern void BX_cursor_to_input (void)
 {
@@ -480,6 +503,13 @@
 	{
 		if (THIS_CHAR)
 		{
+#ifdef	WANT_BIG5
+		  if (NEXT_CHAR && is_big5(THIS_CHAR,NEXT_CHAR) )
+		    {
+		      THIS_POS++;
+		      term_cursor_right();
+		    }
+#endif	/* WANT_BIG5 */
 			THIS_POS++;
 			term_cursor_right();
 		}
@@ -490,6 +520,13 @@
 		{
 			THIS_POS--;
 			term_cursor_left();
+#ifdef WANT_BIG5
+			if ( check_my_role(THIS_POS) == MY_ROLE_LO)
+			  {
+			    THIS_POS--;
+			    term_cursor_left();
+			  }
+#endif /* WANT_BIG5 */
 		}
 	}
 	update_input(NO_UPDATE);
@@ -584,15 +621,33 @@
 BUILT_IN_KEYBINDING(input_delete_character)
 {
 int	pos;
+#ifdef WANT_BIG5
+ int	count=1 ;
+ int	big5_delete=0 ;
+#endif
 	cursor_to_input();
 	in_completion = STATE_NORMAL;
 	if (!THIS_CHAR)
 		return;	
+#ifdef WANT_BIG5
+	if ((THIS_CHAR && NEXT_CHAR) && is_big5(THIS_CHAR, NEXT_CHAR))
+	  {
+		ov_strcpy(&THIS_CHAR, &NTH_CHAR(2));
+		big5_delete=1 ;
+	  }
+	else
+		ov_strcpy(&THIS_CHAR, &NEXT_CHAR);
+#else
 	ov_strcpy(&THIS_CHAR, &NEXT_CHAR);
+#endif /* WANT_BIG5 */
 	if (!(termfeatures & TERM_CAN_DELETE))
 		update_input(UPDATE_FROM_CURSOR);
 	else
 	{
+#ifdef WANT_BIG5
+	  if (big5_delete) count = 2 ;
+	  while ( count -- > 0) {
+#endif
 		term_delete(1);
 		pos = INPUT_ONSCREEN + last_input_screen->co - 1;
 		if (pos < strlen(INPUT_BUFFER))
@@ -601,6 +656,9 @@
 			term_putchar(INPUT_BUFFER[pos]);
 			term_move_cursor(INPUT_CURSOR, INPUT_LINE);
 		}
+#ifdef WANT_BIG5
+	  } /* while -- > 0 */
+#endif /* WANT_BIG5 */
 		update_input(NO_UPDATE);
 	}
 }
@@ -614,6 +672,15 @@
 		char	*ptr = NULL;
 		int	pos;
 
+#ifdef WANT_BIG5
+		int count=1 ;
+#endif
+#ifdef WANT_BIG5
+		if ( check_my_role(THIS_POS -1 ) == MY_ROLE_LO)
+		  count=2 ;
+
+		while (count-->0) {
+#endif
 		ptr = LOCAL_COPY(&THIS_CHAR);
 		strcpy(&(PREV_CHAR), ptr);
 		THIS_POS--;
@@ -650,6 +717,9 @@
 			update_input(UPDATE_FROM_CURSOR);
 #endif
 		}
+#ifdef WANT_BIG5
+		} /* while (count-- > 0)*/
+#endif
 	}
 	if (THIS_POS == MIN_POS)
 		HOLDLAST = NULL;
@@ -688,6 +758,10 @@
 {
 	cursor_to_input();
 	THIS_POS = strlen(INPUT_BUFFER);
+#ifdef WANT_BIG5
+	if (is_big5(PREV_CHAR,THIS_CHAR))
+	  THIS_POS-- ;
+#endif
 	update_input(UPDATE_JUST_CURSOR);
 }
 
@@ -791,11 +865,17 @@
 			THIS_CHAR = key;
 			NEXT_CHAR = 0;
 			ADD_TO_INPUT(ptr);
-			if (termfeatures & TERM_CAN_INSERT)
-				term_insert(key);
+			if (termfeatures & TERM_CAN_INSERT) {
+				if ( check_my_role(THIS_POS) == MY_ROLE_ENG) term_insert(key);
+				else if (check_my_role(THIS_POS) == MY_ROLE_LO) {term_cursor_left(); term_insert(PREV_CHAR); term_insert(key); }
+				if (NEXT_CHAR)
+				    display_flag = UPDATE_FROM_CURSOR;
+			}
 			else
 			{
-				term_putchar(key);
+				if ( check_my_role(THIS_POS) == MY_ROLE_ENG) term_putchar(key);
+				else if (check_my_role(THIS_POS) == MY_ROLE_LO) {term_cursor_left(); term_putchar(PREV_CHAR); term_putchar(key);}
+
 				if (NEXT_CHAR)
 				    display_flag = UPDATE_FROM_CURSOR;
 				else
@@ -806,7 +886,8 @@
 		{
 			THIS_CHAR = key;
 			NEXT_CHAR = 0;
-			term_putchar(key);
+			if ( check_my_role(THIS_POS) == MY_ROLE_ENG) term_putchar(key);
+			else if (check_my_role(THIS_POS) == MY_ROLE_LO) {term_cursor_left(); term_putchar(PREV_CHAR); term_putchar(key);}
 		}
 	}
 	else
@@ -814,7 +895,8 @@
 		if (THIS_CHAR == 0)
 			NEXT_CHAR = 0;
 		THIS_CHAR = key;
-		term_putchar(key);
+		if ( check_my_role(THIS_POS) == MY_ROLE_ENG) term_putchar(key);
+		else if (check_my_role(THIS_POS) == MY_ROLE_LO) {term_cursor_left(); term_putchar(PREV_CHAR); term_putchar(key);}
 	}
 	
 	if (!THIS_POS)
