--- source/screen.c.orig	Thu Aug 10 09:28:50 2000
+++ source/screen.c	Mon Dec  4 03:44:17 2000
@@ -11,6 +11,7 @@
  */
 
 #define __need_putchar_x__
+#define __need_putchars_x__
 #define __need_term_flush__
 #include "irc.h"
 #include "alias.h"
@@ -33,6 +34,7 @@
 #include "commands.h"
 #include "parse.h"
 #include "newio.h"
+#include "kanji.h"
 
 /*
  * When some code wants to override the default lastlog level, and needs
@@ -496,6 +498,7 @@
 		*words,
 		*str,
 		*pos_copy;
+	u_char  c1 = '\0';
 
 	if (recursion)
 		panic("prepare_display() called recursively");
@@ -673,7 +676,8 @@
 
 			default:
 			{
-				if (*ptr == ' ' || strchr(words, *ptr))
+				if (*ptr == ' ' || strchr(words, *ptr)
+				    || (ISKANJI(*ptr) && c1 != '\0'))
 				{
 					if (indent == 0)
 					{
@@ -681,16 +685,30 @@
 						firstwb = pos;
 					}
 					word_break = pos;
-					if (*ptr != ' ' && ptr[1] &&
+					if((ISKANJI(*ptr) && c1 != '\0')) {
+					  if (col < max_cols) {
+					    word_break += 2;
+					    buffer[pos++] = c1;
+					  }else{
+					    word_break--;
+					  }
+					  c1 = '\0';
+					} else if (*ptr != ' ' && ptr[1] &&
 					    (col + 1 < max_cols))
 						word_break++;
+					
 					buffer[pos++] = *ptr;
 				}
 				else
 				{
 					if (indent == -1)
-						indent = col;
-					buffer[pos++] = *ptr;
+					  indent = col;
+					if (ISKANJI(*ptr)) {
+					  c1 = *ptr;
+					} else {
+					  buffer[pos++] = *ptr;
+					}
+
 				}
 				col++;
 				break;
@@ -1494,9 +1512,19 @@
 		 * a LOT faster, as we have already done the processing once
 		 * to make output "terminal friendly".
 		 */
-			if (output)
-				putchar_x(*ptr);
-			out++;
+		  if (ISKANJI(*ptr) && *(ptr + 1)) {
+		    if (output) {
+		      unsigned char k[3];
+		      k[0] = *ptr++; k[1] = *ptr; k[2] = '\0';
+		      putchars_x(k);
+		    }
+		    out += 2;
+		  } else {
+		    if (output) {
+		      putchar_x(*ptr);
+		    }
+		    out++;
+		  }
 		}
 	    }
 	    ptr++;
@@ -2562,6 +2590,10 @@
 		case 1:
 		case 6:
 		{
+		  if(ISKANJI(chr) && ISKANJI(this_char())) {
+		        output[pos++] = chr;
+			output[pos++] = next_char();
+		  } else {
 			int my_gcmode = gcmode;
 
 			/*
@@ -2654,7 +2686,8 @@
 				case 0:
 					break;
 			}
-			break;
+		   }
+		   break;
 		}
 
 
