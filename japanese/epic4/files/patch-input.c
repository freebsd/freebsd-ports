--- source/input.c.orig	Sat Sep 23 01:07:16 2000
+++ source/input.c	Mon Dec  4 03:49:56 2000
@@ -31,6 +31,7 @@
 #include "vars.h"
 #include "window.h"
 #include "output.h"
+#include "kanji.h"
 #include <sys/ioctl.h>		/* XXX ugh */
 
 /*
@@ -70,7 +71,6 @@
 #define INPUT_LINE 		current_screen->input_line
 #define CUT_BUFFER		cut_buffer
 #define SET_CUT_BUFFER(x)	malloc_strcpy(&CUT_BUFFER, x);
-
 #define BUILT_IN_KEYBINDING(x) void x (char key, char *string)
 
 
@@ -81,9 +81,19 @@
 
 	while (*str && i < len)
 	{
-		term_putchar(*str);
-		str++, i++;
+	        if (ISKANJI(*str) && ISKANJI(*(str+1))) {
+		  if (i < len - 1) {
+		    term_putchar(*str, *(str+1));
+		    str += 2; i += 2;
+		  } else {
+		    break; /* goto END */
+		  }
+		} else {
+		  term_putchar(*str, '\0');
+		  str++, i++;
+		}
 	}
+	/* END: */
 	return i;
 }
 
@@ -321,9 +331,16 @@
 	 */
 	if (START_ZONE == WIDTH)
 		INPUT_ONSCREEN = 0;
-	else
+	else {
+	        int pos = THIS_POS;
 		INPUT_ONSCREEN = START_ZONE - WIDTH - INPUT_PROMPT_LEN;
-
+		/* adjust kanji */
+		while (pos > INPUT_ONSCREEN) {
+		  ISKANJI(INPUT_BUFFER[pos - 1]) ? pos -= 2 : pos--;
+		}
+		INPUT_ONSCREEN = pos;
+	}
+		
 	/*
 	 * And the cursor is simply how many characters away THIS_POS is
 	 * from the first column on the screen.
@@ -468,16 +485,28 @@
 	{
 		if (THIS_CHAR)
 		{
-			THIS_POS++;
-			term_cursor_right();
+		        if (ISKANJI (THIS_CHAR)) {
+			  THIS_POS+=2;
+			  term_right(2);
+			}else{
+			  THIS_POS++;
+			  term_cursor_right();
+			}
 		}
 	}
 	else
 	{
 		if (THIS_POS > MIN_POS)
 		{
-			THIS_POS--;
-			term_cursor_left();
+		  	if (THIS_POS > MIN_POS - 1
+			    && ISKANJI(PREV_CHAR)
+			    && ISKANJI(INPUT_BUFFER[THIS_POS-2])) {
+			  THIS_POS -= 2;
+			  term_left(2);
+			}else{
+			  THIS_POS--;
+			  term_cursor_left();
+			}
 		}
 	}
 	update_input(NO_UPDATE);
@@ -590,7 +619,7 @@
 	update_input(UPDATE_JUST_CURSOR);
 }
 
-static void	input_delete_char_from_screen (void)
+static void	input_delete_char_from_screen (int count)
 {
 	/*
 	 * Remove the current character from the screen's display.
@@ -607,7 +636,7 @@
 		/*
 		 * Delete the character.  This is the simple part.
 		 */
-		term_delete(1);
+		term_delete(count);
 
 		/*
 		 * So right now we have a blank space at the right of the
@@ -615,14 +644,14 @@
 		 * is out in that position, we need to find it and display it.
 		 */
 		if (INPUT_ONSCREEN == 0)		/* UGH! */
-			pos = last_input_screen->co - INPUT_PROMPT_LEN - 1;
+			pos = last_input_screen->co - INPUT_PROMPT_LEN - count;
 		else
-			pos = INPUT_ONSCREEN + last_input_screen->co - 1;
+			pos = INPUT_ONSCREEN + last_input_screen->co - count;
 
 		if (pos < strlen(INPUT_BUFFER))
 		{
-			term_move_cursor(last_input_screen->co - 1, INPUT_LINE);
-			term_putchar(INPUT_BUFFER[pos]);
+			term_move_cursor(last_input_screen->co - count, INPUT_LINE);
+			term_putchar(INPUT_BUFFER[pos], '\0');
 			term_move_cursor(INPUT_CURSOR, INPUT_LINE);
 		}
 
@@ -637,6 +666,7 @@
  */
 BUILT_IN_KEYBINDING(input_delete_character)
 {
+        int count;
 	cursor_to_input();
 
 	/*
@@ -646,12 +676,14 @@
 	if (!THIS_CHAR)
 		return;
 
+	count = ISKANJI(THIS_CHAR) ? 2 : 1;
+	
 	/* 
 	 * Remove the current character from the logical buffer
 	 * and also from the screen.
 	 */
-	ov_strcpy(&THIS_CHAR, &NEXT_CHAR);
-	input_delete_char_from_screen();
+	ov_strcpy(&THIS_CHAR, &INPUT_BUFFER[THIS_POS+count]);
+	input_delete_char_from_screen(count);
 }
 
 
@@ -804,7 +836,24 @@
  */
 BUILT_IN_KEYBINDING(input_add_character)
 {
+        static u_char c1 = '\0', c2;
 	int	display_flag = NO_UPDATE;
+	int     length;
+
+	/* add by atsushi */
+	if (ISKANJI(key)) {
+	  if (c1 == '\0') { /* kanji 1st char */
+	    c1 = key;
+	    return;
+	  }else{ /* kanji 2nd char */
+	    c2 = key;
+	    length  = 2;
+	  }
+	}else{
+	  c1 = key;
+	  length = 1;
+	}
+	/* end add */
 
 	cursor_to_input();
 
@@ -812,7 +861,7 @@
 		term_echo(last_input_screen->promptlist->echo);
 
 	/* Don't permit the input buffer to get too big. */
-	if (THIS_POS >= INPUT_BUFFER_SIZE)
+	if (THIS_POS + length > INPUT_BUFFER_SIZE) /* change */
 	{
 		term_echo(1);
 		return;
@@ -832,7 +881,12 @@
 			 * Add to logical buffer
 			 */
 			ptr = LOCAL_COPY(&(THIS_CHAR));
-			THIS_CHAR = key;
+			/* add */
+			THIS_CHAR = c1;
+			if (length > 1) {
+			  THIS_POS++;
+			  THIS_CHAR = c2;
+			} /* end add */
 			NEXT_CHAR = 0;
 			ADD_TO_INPUT(ptr);
 
@@ -843,7 +897,7 @@
 				term_insert(key);
 			else
 			{
-				term_putchar(key);
+				term_putchar(c1, c2);
 				if (NEXT_CHAR)
 					display_flag = UPDATE_FROM_CURSOR;
 				else
@@ -855,26 +909,41 @@
 			/*
 			 * Add to logical buffer
 			 */
-			THIS_CHAR = key;
+		        /* add */
+			THIS_CHAR = c1;
+		        if (length > 1) {
+			  THIS_POS++;
+			  THIS_CHAR = c2;
+			} /* end add */
 			NEXT_CHAR = 0;
 
 			/* Add to display screen */
-			term_putchar(key);
+			term_putchar(c1, c2);
 		}
 	}
 
 	/* Overstrike mode.  Much simpler. */
+	/* Maybe we must change here (atsushi) */
 	else
 	{
-		if (THIS_CHAR == 0)
+	        if (THIS_CHAR == 0)
 			NEXT_CHAR = 0;
-		THIS_CHAR = key;
-		term_putchar(key);
+		THIS_CHAR = c1;
+		/* add */
+		 if (length > 1) {
+		   THIS_POS++;
+		   if (THIS_CHAR == 0)
+		         NEXT_CHAR = 0;
+		   THIS_CHAR = c2;
+		 } /* end add */
+
+		term_putchar(c1, c2);
 	}
 
 	THIS_POS++;
 	update_input(display_flag);
 	term_echo(1);
+        c1 = '\0';
 }
 
 /* input_clear_to_eol: erases from the cursor to the end of the input buffer */
@@ -935,8 +1004,8 @@
 	cursor_to_input();
 	if (last_input_screen->buffer_pos > MIN_POS)
 	{
-		u_char	c1, c2;
-		int	pos, end_of_line = 0;
+		u_char	c1[2], c2[2];
+		int	pos, ptr, end_of_line = 0;
 
 		/*
 		 * If we're in the middle of the input buffer,
@@ -956,6 +1025,9 @@
 		{
 			pos = THIS_POS - 1;
 			end_of_line = 1;
+			if (ISKANJI(INPUT_BUFFER[pos])) {
+			  pos--;
+			}
 		}
 
 		/*
@@ -968,25 +1040,49 @@
 		/*
 		 * Swap the two characters
 		 */
-		c1 = INPUT_BUFFER[pos];
-		c2 = INPUT_BUFFER[pos] = INPUT_BUFFER[pos - 1];
-		INPUT_BUFFER[pos - 1] = c1;
+		if (pos > 1 &&
+		    ISKANJI(INPUT_BUFFER[pos - 1]) &&
+		    ISKANJI(INPUT_BUFFER[pos - 2])) {
+		  c2[0] = INPUT_BUFFER[pos - 2];
+		  c2[1] = INPUT_BUFFER[pos - 1];
+		  ptr = pos - 2;
+		} else {
+		  c2[0] = INPUT_BUFFER[pos - 1];
+		  c2[1] = '\0';
+		  ptr = pos - 1;
+		}
 
+		if (ISKANJI(INPUT_BUFFER[pos])) {
+		  c1[0] = INPUT_BUFFER[ptr++] = INPUT_BUFFER[pos];
+		  c1[1] = INPUT_BUFFER[ptr++] = INPUT_BUFFER[pos + 1];
+		} else {
+		  c1[0] = INPUT_BUFFER[ptr++] = INPUT_BUFFER[pos];
+		  c1[1] = '\0';
+		}
+		/* adjust THIS_POS */
+		if (!end_of_line)
+		  THIS_POS = ptr;
+		
+		INPUT_BUFFER[ptr++] = c2[0];
+		if (c2[1]) {
+		  INPUT_BUFFER[ptr] = c2[1];
+		}
+		
 		/*
 		 * Adjust the cursor and output the new chars.
 		 */
-		term_cursor_left();
 		if (end_of_line)
-			term_cursor_left();
-		term_putchar(c1);
-		term_putchar(c2);
+		  c1[1] ? term_left(2) : term_cursor_left();
+		c2[1] ? term_left(2) : term_cursor_left();
+		term_putchar(c1[0], c1[1]);
+		term_putchar(c2[0], c2[1]);
 
 		/*
 		 * Move the cursor back onto 'c2', if we're not at
 		 * the end of the input line.
 		 */
 		if (!end_of_line)
-			term_cursor_left();
+		  c2[1] ? term_left(2) : term_cursor_left();
 
 		/*
 		 * Reset the internal cursor.
@@ -1232,7 +1328,6 @@
 
 	if (xxx_return)
 		return;
-
 	/* If the high bit is set, mangle it as neccesary. */
 	if (key & 0x80)
 	{
@@ -1242,9 +1337,8 @@
 			key &= ~0x80;
 		}
 		else if (!term_eight_bit())
-			key &= ~0x80;
+		  key &= ~0x80;
 	}
-
 	extended_key = key;
 
 	/* If we just hit the quote character, add this character literally */
