*** src/input.c.old	Mon Feb 12 14:32:17 2001
--- src/input.c	Mon Feb 12 14:51:49 2001
***************
*** 103,107 ****
--- 103,120 ----
  	int	c, i = 0;
  	int	j;
+ 	char *sright;	/* substring to the right of the cursor */
+ 	int ri = 0;		/* position in right-string */
  
+ 	/* Inserts and deletes are always performed on the left-string,
+ 	 * but we'll also have a right-string 'sright' to hold characters
+ 	 * which are on the right of the cursor [insertion point].
+ 	 *
+ 	 * Think of 'sright' as a stack -- we push chars into it when the cursor
+ 	 * moves left, and we pop chars off it when the cursor moves right again.
+ 	 * At the end of the function, we'll pop off any remaining characters
+ 	 * onto the end of 's'
+ 	 */
+ 	sright = calloc(sizeof(char), size);
+ 
  	/* if a character already has been typed */
  	if (firstchar != '\0') {
***************
*** 114,121 ****
  	/* until the end of the line is reached */
  	while ((c = mygetch()) != '\r' && c != '\n' && c != KEY_ENTER) {
! 		if (c == erasechar() || c == KEY_BACKSPACE || c == DEL || c == ctrl('H') ) {
  			/* erase */
  			if (i > 0) {
! 				addstr("\b \b");
  				--i;
  			}
--- 127,177 ----
  	/* until the end of the line is reached */
  	while ((c = mygetch()) != '\r' && c != '\n' && c != KEY_ENTER) {
! 
! 		if (c == KEY_LEFT || c == ctrl('B')) {	/* left */
! 			if (i > 0) {
! 				addch('\b');
! 				/* move this char into the second (rhs) string */
! 				sright[ri++] = s[--i];
! 			}
! 		}
! 		else if (c == KEY_RIGHT || c == ctrl('F')) {	/* right */
! 			if (i < size && ri > 0) {
! 				/* move this char to the left of the cursor */
! 				s[i++] = sright[--ri];
! 				addch(s[i-1]);
! 			}
! 		}
! 		else if (
! 		#ifdef KEY_HOME
! 			c == KEY_HOME ||
! 		#endif
! 			c == ctrl('A') ) {
! 			while ( i > 0 ) {
! 				sright[ri++] = s[--i];
! 				addch('\b');
! 				addch(s[i]);
! 				addch('\b');
! 			}
! 		}
! 		else if (
! 		#ifdef KEY_END
! 			c == KEY_END ||
! 		#endif
! 			c == ctrl('E') ) {
! 			while ( ri > 0 ) {
! 				s[i++] = sright[--ri];
! 				addch(s[i-1]);
! 			}
! 		}
! 		else if (c == erasechar() || c == KEY_BACKSPACE || c == DEL || c == ctrl('H') ) {
  			/* erase */
  			if (i > 0) {
! 				if (ri == 0)  {
! 					addstr("\b \b");
! 				} else {
! 					addch('\b');
! 					delch();
! 				}
! 				s[i] = '\0';
  				--i;
  			}
***************
*** 139,144 ****
  			/* if it will fit on the line */
  			if (i < size) {
- 				addch(c);	/* display it */
  				s[i++] = c;	/* save it */
  			}
  		}
--- 195,205 ----
  			/* if it will fit on the line */
  			if (i < size) {
  				s[i++] = c;	/* save it */
+ 				if (ri == 0) {
+ 					addch(c);	/* display it */
+ 				} else {
+ 					insch(c);	/* display it */
+ 					addch(c);	/* advance cursor */
+ 				}
  			}
  		}
***************
*** 155,162 ****
  		}
  		/* return on an empty line to allow a command to be entered */
! 		if (firstchar != '\0' && i == 0) {
  			break;
  		}
  	}
  	s[i] = '\0';
  	return(i);
--- 216,232 ----
  		}
  		/* return on an empty line to allow a command to be entered */
! 		if (firstchar != '\0' && (i+ri) == 0) {
  			break;
  		}
  	}
+ 
+ 	/* move any remaining chars on the rhs of the cursor
+ 	 * onto the end of our string
+ 	 */
+ 	for (; ri > 0; ) {
+ 		s[i++] = sright[--ri];
+ 	}
+ 	free(sright);
+ 
  	s[i] = '\0';
  	return(i);
