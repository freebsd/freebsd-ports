Revision 212191
libedit: Do not move the cursor for ed-delete-next-char in emacs mode.

This makes ed-delete-next-char suitable for mapping to the <Delete> key.

Behaviour in vi mode is unchanged (for 'x').

--- common.c	2007/03/11 18:30:22	167457
+++ common.c	2010/09/03 22:24:26	212191
@@ -163,15 +163,12 @@
 				return (CC_ERROR);
 #endif
 			}
-		} else {
-			if (el->el_line.cursor != el->el_line.buffer)
-				el->el_line.cursor--;
-			else
-				return (CC_ERROR);
-		}
+		} else
+			return (CC_ERROR);
 	}
 	c_delafter(el, el->el_state.argument);	/* delete after dot */
-	if (el->el_line.cursor >= el->el_line.lastchar &&
+	if (el->el_map.type == MAP_VI &&
+	    el->el_line.cursor >= el->el_line.lastchar &&
 	    el->el_line.cursor > el->el_line.buffer)
 			/* bounds check */
 		el->el_line.cursor = el->el_line.lastchar - 1;
