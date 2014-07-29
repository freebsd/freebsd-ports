--- source/screen.c~	Mon Jan  8 15:06:18 2001
+++ source/screen.c	Mon Jan  8 15:05:53 2001
@@ -548,6 +548,15 @@
 
 			default:
 			{
+#ifdef WANT_BIG5
+			    if (is_big5((char)*ptr,(char)*(ptr+1)))
+			      {
+				    buffer[pos++] = *ptr++;
+				    col++ ;
+				    if ( col + 2 >= max_cols ) 
+				      word_break = pos-1 ;
+			      }
+#endif
 				if (*ptr == ' ' || strchr(words, *ptr))
 				{
 					if (indent == 0)
@@ -586,7 +595,14 @@
 			if (!word_break || (flags & PREPARE_NOWRAP))
 				word_break = max_cols /*pos - 1*/;
 			else if (col > max_cols)
+#ifdef WANT_BIG5
+				if (is_big5((char)buffer[pos-2], (char)buffer[pos-1]))
+				  word_break = pos -2 ;
+				else
+				  word_break = pos -1 ;
+#else
 				word_break = pos - 1;
+#endif
 								
 			/*
 			 * XXXX Massive hackwork here.
