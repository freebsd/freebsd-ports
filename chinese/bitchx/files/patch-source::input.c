--- source/input.c~	Mon Jan  8 15:06:30 2001
+++ source/input.c	Mon Jan  8 01:09:28 2001
@@ -89,6 +89,7 @@
 #define MIN_CHAR 		INPUT_BUFFER[MIN_POS]
 #define PREV_CHAR 		INPUT_BUFFER[THIS_POS-1]
 #define NEXT_CHAR 		INPUT_BUFFER[THIS_POS+1]
+#define	NTH_CHAR(offset)	INPUT_BUFFER[THIS_POS+(offset)]
 #define ADD_TO_INPUT(x) 	strmcat(INPUT_BUFFER, (x), INPUT_BUFFER_SIZE);
 #define INPUT_ONSCREEN 		current_screen->input_visible
 #define INPUT_VISIBLE 		INPUT_BUFFER[INPUT_ONSCREEN]
@@ -473,6 +474,13 @@
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
@@ -483,6 +491,13 @@
 		{
 			THIS_POS--;
 			term_cursor_left();
+#ifdef WANT_BIG5
+			if (is_big5(PREV_CHAR,THIS_CHAR))
+			  {
+			    THIS_POS--;
+			    term_cursor_left();
+			  }
+#endif /* WANT_BIG5 */
 		}
 	}
 	update_input(NO_UPDATE);
@@ -577,15 +592,33 @@
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
@@ -594,6 +627,9 @@
 			term_putchar(INPUT_BUFFER[pos]);
 			term_move_cursor(INPUT_CURSOR, INPUT_LINE);
 		}
+#ifdef WANT_BIG5
+	  } /* while -- > 0 */
+#endif /* WANT_BIG5 */
 		update_input(NO_UPDATE);
 	}
 }
@@ -607,6 +643,14 @@
 		char	*ptr = NULL;
 		int	pos;
 
+#ifdef WANT_BIG5
+		int count=1 ;
+#endif
+#ifdef WANT_BIG5
+		if ( *(&PREV_CHAR-sizeof(char)) && (is_big5(*(&PREV_CHAR-sizeof(char)),PREV_CHAR)))
+		  count=2 ;
+		while (count-->0) {
+#endif
 		ptr = LOCAL_COPY(&THIS_CHAR);
 		strcpy(&(PREV_CHAR), ptr);
 		THIS_POS--;
@@ -643,6 +687,9 @@
 			update_input(UPDATE_FROM_CURSOR);
 #endif
 		}
+#ifdef WANT_BIG5
+		} /* while (count-- > 0)*/
+#endif
 	}
 	if (THIS_POS == MIN_POS)
 		HOLDLAST = NULL;
@@ -681,6 +728,10 @@
 {
 	cursor_to_input();
 	THIS_POS = strlen(INPUT_BUFFER);
+#ifdef WANT_BIG5
+	if (is_big5(PREV_CHAR,THIS_CHAR))
+	  THIS_POS-- ;
+#endif
 	update_input(UPDATE_JUST_CURSOR);
 }
 
