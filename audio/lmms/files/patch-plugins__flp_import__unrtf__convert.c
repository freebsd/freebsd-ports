--- plugins/flp_import/unrtf/convert.c.orig	2009-02-24 07:34:26.000000000 +0900
+++ plugins/flp_import/unrtf/convert.c	2009-04-10 22:19:43.000000000 +0900
@@ -650,8 +650,8 @@
 {
 	if (!have_printed_body) {
 		if (!inline_mode) {
-			outstring+=QString().sprintf(op->header_end);
-			outstring+=QString().sprintf(op->body_begin);
+			outstring+=QString().sprintf("%s", op->header_end);
+			outstring+=QString().sprintf("%s", op->body_begin);
 		}
 		within_header = FALSE;
 		have_printed_body = TRUE;
@@ -926,7 +926,7 @@
 
 			if (!inline_mode) {
 				if (!strcmp("\\title", s)) {
-					outstring+=QString().sprintf(op->document_title_begin);
+					outstring+=QString().sprintf("%s", op->document_title_begin);
 					w2=child->next;
 					while (w2) {
 						char *s2 = word_string(w2);
@@ -951,18 +951,18 @@
 								s3 = op_translate_char (op, charset_type, charset_codepage, ch, numchar_table);
 								if (!s3 || !*s3)
 								{
-									outstring+=QString().sprintf(op->comment_begin);
+									outstring+=QString().sprintf("%s", op->comment_begin);
 									outstring+=QString().sprintf("char 0x%02x",ch);
-									outstring+=QString().sprintf(op->comment_end);
+									outstring+=QString().sprintf("%s", op->comment_end);
 
 								}
 								else
 								{
 									if (op->word_begin)
-										outstring+=QString().sprintf(op->word_begin);
+										outstring+=QString().sprintf("%s", op->word_begin);
 									outstring+=QString().sprintf("%s", s3);
 									if (op->word_end)
-										outstring+=QString().sprintf(op->word_end);
+										outstring+=QString().sprintf("%s", op->word_end);
 								}
 							}
 						}
@@ -970,10 +970,10 @@
 #endif
 						w2 = w2->next;
 					}
-					outstring+=QString().sprintf(op->document_title_end);
+					outstring+=QString().sprintf("%s", op->document_title_end);
 				}
 				else if (!strcmp("\\keywords", s)) {
-					outstring+=QString().sprintf(op->document_keywords_begin);
+					outstring+=QString().sprintf("%s", op->document_keywords_begin);
 					w2=child->next;
 					while (w2) {
 						char *s2 = word_string(w2);
@@ -981,10 +981,10 @@
 							outstring+=QString().sprintf("%s,", s2);
 						w2 = w2->next;
 					}
-					outstring+=QString().sprintf(op->document_keywords_end);
+					outstring+=QString().sprintf("%s", op->document_keywords_end);
 				}
 				else if (!strcmp("\\author", s)) {
-					outstring+=QString().sprintf(op->document_author_begin);
+					outstring+=QString().sprintf("%s", op->document_author_begin);
 					w2=child->next;
 					while (w2) {
 						char *s2 = word_string(w2);
@@ -992,7 +992,7 @@
 							outstring+=QString().sprintf("%s", s2);
 						w2 = w2->next;
 					}
-					outstring+=QString().sprintf(op->document_author_end);
+					outstring+=QString().sprintf("%s", op->document_author_end);
 				}
 				else if (!strcmp("\\comment", s)) {
 					outstring+=QString().sprintf("%s",op->comment_begin);
@@ -1312,9 +1312,9 @@
 							    w4=w4->next;
 						    if (w4) {
 							    s4=word_string(w4);
-							    outstring+=QString().sprintf(op->hyperlink_begin);
+							    outstring+=QString().sprintf("%s", op->hyperlink_begin);
 							    outstring+=QString().sprintf("%s", s4);
-							    outstring+=QString().sprintf(op->hyperlink_end);
+							    outstring+=QString().sprintf("%s", op->hyperlink_end);
 							    return TRUE;
 						    }
 					    	
@@ -1423,7 +1423,7 @@
 	int need= 8-(total_chars_this_line%8);
 	total_chars_this_line += need;
 	while(need>0) {
-		outstring+=QString().sprintf(op->forced_space);
+		outstring+=QString().sprintf("%s", op->forced_space);
 		need--;
 	}
 	outstring+=QString().sprintf("\n");
@@ -1643,7 +1643,7 @@
 static int 
 cmd_bullet (Word *w, int align, char has_param, int param) {
 	if (op->chars.bullet) {
-		outstring+=QString().sprintf(op->chars.bullet);
+		outstring+=QString().sprintf("%s", op->chars.bullet);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1658,7 +1658,7 @@
 static int 
 cmd_ldblquote (Word *w, int align, char has_param, int param) {
 	if (op->chars.left_dbl_quote) {
-		outstring+=QString().sprintf(op->chars.left_dbl_quote);
+		outstring+=QString().sprintf("%s", op->chars.left_dbl_quote);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1675,7 +1675,7 @@
 static int 
 cmd_rdblquote (Word *w, int align, char has_param, int param) {
 	if (op->chars.right_dbl_quote) {
-		outstring+=QString().sprintf(op->chars.right_dbl_quote);
+		outstring+=QString().sprintf("%s", op->chars.right_dbl_quote);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1691,7 +1691,7 @@
 static int 
 cmd_lquote (Word *w, int align, char has_param, int param) {
 	if (op->chars.left_quote) {
-		outstring+=QString().sprintf(op->chars.left_quote);
+		outstring+=QString().sprintf("%s", op->chars.left_quote);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1708,7 +1708,7 @@
 static int 
 cmd_nonbreaking_space (Word *w, int align, char has_param, int param) {
 	if (op->chars.nonbreaking_space) {
-		outstring+=QString().sprintf(op->chars.nonbreaking_space);
+		outstring+=QString().sprintf("%s", op->chars.nonbreaking_space);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1725,7 +1725,7 @@
 static int 
 cmd_nonbreaking_hyphen (Word *w, int align, char has_param, int param) {
 	if (op->chars.nonbreaking_hyphen) {
-		outstring+=QString().sprintf(op->chars.nonbreaking_hyphen);
+		outstring+=QString().sprintf("%s", op->chars.nonbreaking_hyphen);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1742,7 +1742,7 @@
 static int 
 cmd_optional_hyphen (Word *w, int align, char has_param, int param) {
 	if (op->chars.optional_hyphen) {
-		outstring+=QString().sprintf(op->chars.optional_hyphen);
+		outstring+=QString().sprintf("%s", op->chars.optional_hyphen);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1758,7 +1758,7 @@
 static int 
 cmd_emdash (Word *w, int align, char has_param, int param) {
 	if (op->chars.emdash) {
-		outstring+=QString().sprintf(op->chars.emdash);
+		outstring+=QString().sprintf("%s", op->chars.emdash);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1775,7 +1775,7 @@
 static int 
 cmd_endash (Word *w, int align, char has_param, int param) {
 	if (op->chars.endash) {
-		outstring+=QString().sprintf(op->chars.endash);
+		outstring+=QString().sprintf("%s", op->chars.endash);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1792,7 +1792,7 @@
 static int 
 cmd_rquote (Word *w, int align, char has_param, int param) {
 	if (op->chars.right_quote) {
-		outstring+=QString().sprintf(op->chars.right_quote);
+		outstring+=QString().sprintf("%s", op->chars.right_quote);
 		++total_chars_this_line; /* \tab */
 	}
 	return FALSE;
@@ -1808,7 +1808,7 @@
 static int 
 cmd_par (Word *w, int align, char has_param, int param) {
 	if (op->line_break) {
-		outstring+=QString().sprintf(op->line_break);
+		outstring+=QString().sprintf("%s", op->line_break);
 		total_chars_this_line = 0; /* \tab */
 	}
 	return FALSE;
@@ -1825,7 +1825,7 @@
 static int 
 cmd_line (Word *w, int align, char has_param, int param) {
 	if (op->line_break) {
-		outstring+=QString().sprintf(op->line_break);
+		outstring+=QString().sprintf("%s", op->line_break);
 		total_chars_this_line = 0; /* \tab */
 	}
 	return FALSE;
@@ -1841,7 +1841,7 @@
 
 static int cmd_page (Word *w, int align, char has_param, int param) {
 	if (op->page_break) {
-		outstring+=QString().sprintf(op->page_break);
+		outstring+=QString().sprintf("%s", op->page_break);
 		total_chars_this_line = 0; /* \tab */
 	}
 	return FALSE;
@@ -2337,7 +2337,7 @@
 static int cmd_sect (Word *w, int align, char has_param, int param) {
 	/* XX kludge */
 	if (op->paragraph_begin) {
-		outstring+=QString().sprintf(op->paragraph_begin);
+		outstring+=QString().sprintf("%s", op->paragraph_begin);
 	}
 	return FALSE;
 }
@@ -2351,9 +2351,9 @@
 
 static int cmd_shp (Word *w, int align, char has_param, int param) {
 	if (op->comment_begin) {
-		outstring+=QString().sprintf(op->comment_begin);
+		outstring+=QString().sprintf("%s", op->comment_begin);
 		outstring+=QString().sprintf("Drawn Shape (ignored--not implemented yet)");
-		outstring+=QString().sprintf(op->comment_end);	/* daved 0.20.2 */
+		outstring+=QString().sprintf("%s", op->comment_end);	/* daved 0.20.2 */
 	}
 
 	return FALSE;
@@ -2404,17 +2404,17 @@
 		charset_codepage = &codepages[i];
 		if (charset_codepage->cp == param) {
 			if (op->comment_begin) {
-				outstring+=QString().sprintf(op->comment_begin);
+				outstring+=QString().sprintf("%s", op->comment_begin);
 				outstring+=QString().sprintf("document uses ANSI codepage %d character set", param);
-				outstring+=QString().sprintf(op->comment_end);
+				outstring+=QString().sprintf("%s", op->comment_end);
 			}
 			break;
 		}
 	}
 	if ((charset_codepage == NULL || charset_codepage->cp == 0) && op->comment_begin) {
-		outstring+=QString().sprintf(op->comment_begin);
+		outstring+=QString().sprintf("%s", op->comment_begin);
 		outstring+=QString().sprintf("document uses default ANSI codepage character set");
-		outstring+=QString().sprintf(op->comment_end);
+		outstring+=QString().sprintf("%s", op->comment_end);
 	}
 	return FALSE;
 }
@@ -3106,7 +3106,7 @@
 	if (simulate_smallcaps) {
 		if (*s >= 'a' && *s <= 'z') {
 			state=SMALL;
-			outstring+=QString().sprintf(op->smaller_begin);
+			outstring+=QString().sprintf("%s", op->smaller_begin);
 		}
 		else
 			state=BIG;
@@ -3136,13 +3136,13 @@
 			ch = *s;
 			if (ch >= 'a' && ch <= 'z') {
 				if (state==BIG)
-					outstring+=QString().sprintf(op->smaller_begin);
+					outstring+=QString().sprintf("%s", op->smaller_begin);
 				state=SMALL;
 			}
 			else
 			{
 				if (state==SMALL)
-					outstring+=QString().sprintf(op->smaller_end);
+					outstring+=QString().sprintf("%s", op->smaller_end);
 				state=BIG;
 			}
 		}
@@ -3168,7 +3168,7 @@
 	have_printed_cell_end = FALSE;
 	attrstack_push();
 	starting_body();
-	outstring+=QString().sprintf(op->table_begin);
+	outstring+=QString().sprintf("%s", op->table_begin);
 }
 
 
@@ -3186,12 +3186,12 @@
 	if (within_table) {
 		if (!have_printed_cell_end) {
 			attr_pop_dump();
-			outstring+=QString().sprintf(op->table_cell_end);
+			outstring+=QString().sprintf("%s", op->table_cell_end);
 		}
 		if (!have_printed_row_end) {
-			outstring+=QString().sprintf(op->table_row_end);
+			outstring+=QString().sprintf("%s", op->table_row_end);
 		}
-		outstring+=QString().sprintf(op->table_end);
+		outstring+=QString().sprintf("%s", op->table_end);
 		within_table=FALSE;
 		have_printed_row_begin = FALSE;
 		have_printed_cell_begin = FALSE;
@@ -3213,13 +3213,13 @@
 starting_text() {
 	if (within_table) {
 		if (!have_printed_row_begin) {
-			outstring+=QString().sprintf(op->table_row_begin);
+			outstring+=QString().sprintf("%s", op->table_row_begin);
 			have_printed_row_begin=TRUE;
 			have_printed_row_end=FALSE;
 			have_printed_cell_begin=FALSE;
 		}
 		if (!have_printed_cell_begin) {
-			outstring+=QString().sprintf(op->table_cell_begin);
+			outstring+=QString().sprintf("%s", op->table_cell_begin);
 			attrstack_express_all();
 			have_printed_cell_begin=TRUE;
 			have_printed_cell_end=FALSE;
@@ -3246,15 +3246,15 @@
 	switch (align) 
 	{
 	case ALIGN_CENTER:
-		outstring+=QString().sprintf(op->center_begin); 
+		outstring+=QString().sprintf("%s", op->center_begin); 
 		break;
 	case ALIGN_LEFT:
 		break;
 	case ALIGN_RIGHT:
-		outstring+=QString().sprintf(op->align_right_begin);
+		outstring+=QString().sprintf("%s", op->align_right_begin);
 		break;
 	case ALIGN_JUSTIFY:
-		outstring+=QString().sprintf(op->align_right_begin); /* This is WRONG! */
+		outstring+=QString().sprintf("%s", op->align_right_begin); /* This is WRONG! */
 		break;
 	}
 }
@@ -3273,16 +3273,16 @@
 {
 	switch (align) {
 	case ALIGN_CENTER:
-		outstring+=QString().sprintf(op->center_end);
+		outstring+=QString().sprintf("%s", op->center_end);
 		break;
 	case ALIGN_LEFT:
-	  /* outstring+=QString().sprintf(op->align_left_end); */
+	  /* outstring+=QString().sprintf("%s", op->align_left_end); */
 		break;
 	case ALIGN_RIGHT:
-		outstring+=QString().sprintf(op->align_right_end);
+		outstring+=QString().sprintf("%s", op->align_right_end);
 		break;
 	case ALIGN_JUSTIFY:
-		outstring+=QString().sprintf(op->justify_end);
+		outstring+=QString().sprintf("%s", op->justify_end);
 		break;
 	}
 }
@@ -3391,12 +3391,12 @@
 					total_chars_this_line += strlen(s);
 
 					if (op->word_begin)
-						outstring+=QString().sprintf(op->word_begin);
+						outstring+=QString().sprintf("%s", op->word_begin);
 
 					print_with_special_exprs (s);
 
 					if (op->word_end)
-						outstring+=QString().sprintf(op->word_end);
+						outstring+=QString().sprintf("%s", op->word_end);
 				}
 
 
@@ -3456,17 +3456,17 @@
 					is_cell_group=TRUE;
 					if (!have_printed_cell_begin) {
 						/* Need this with empty cells */
-						outstring+=QString().sprintf(op->table_cell_begin);
+						outstring+=QString().sprintf("%s", op->table_cell_begin);
 						attrstack_express_all();
 					}
 					attr_pop_dump();
-					outstring+=QString().sprintf(op->table_cell_end);
+					outstring+=QString().sprintf("%s", op->table_cell_end);
 					have_printed_cell_begin = FALSE;
 					have_printed_cell_end=TRUE;
 				}
 				else if (!strcmp (s, "row")) {
 					if (within_table) {
-						outstring+=QString().sprintf(op->table_row_end);
+						outstring+=QString().sprintf("%s", op->table_row_end);
 						have_printed_row_begin = FALSE;
 						have_printed_row_end=TRUE;
 					} else {
@@ -3496,10 +3496,10 @@
 						outstring+=QString().sprintf("%s",op->comment_end);
 					} else {
 						if (op->word_begin)
-							outstring+=QString().sprintf(op->word_begin);
+							outstring+=QString().sprintf("%s", op->word_begin);
 						outstring+=QString().sprintf("%s", s2);
 						if (op->word_end)
-							outstring+=QString().sprintf(op->word_end);
+							outstring+=QString().sprintf("%s", op->word_end);
 					}
 				}
 				else
@@ -3529,9 +3529,9 @@
 
 					if (!hip) {
 						if (debug_mode) {
-							outstring+=QString().sprintf(op->comment_begin);
+							outstring+=QString().sprintf("%s", op->comment_begin);
 							outstring+=QString().sprintf("Unfamiliar RTF command: %s (HashIndex not found)", s);
-							outstring+=QString().sprintf(op->comment_end); /* daved 0.20.2 */
+							outstring+=QString().sprintf("%s", op->comment_end); /* daved 0.20.2 */
 						}
 					}
 					else {
@@ -3610,9 +3610,9 @@
 	if (within_picture) {
 		if(pictfile) { 
 			fclose(pictfile);
-			outstring+=QString().sprintf(op->imagelink_begin);
+			outstring+=QString().sprintf("%s", op->imagelink_begin);
 			outstring+=QString().sprintf("%s", picture_path);
-			outstring+=QString().sprintf(op->imagelink_end);
+			outstring+=QString().sprintf("%s", op->imagelink_end);
 		}
 		within_picture=FALSE;
 	}
@@ -3665,8 +3665,8 @@
 
 	outstring = "";
 	if (!inline_mode) {
-		outstring+=QString().sprintf(op->document_begin);
-		outstring+=QString().sprintf(op->header_begin);
+		outstring+=QString().sprintf("%s", op->document_begin);
+		outstring+=QString().sprintf("%s", op->header_begin);
 	}
 
 	within_header=TRUE;
@@ -3677,8 +3677,8 @@
 	end_table();
 
 	if (!inline_mode) {
-		outstring+=QString().sprintf(op->body_end);
-		outstring+=QString().sprintf(op->document_end);
+		outstring+=QString().sprintf("%s", op->body_end);
+		outstring+=QString().sprintf("%s", op->document_end);
 	}
 	_s = outstring;
 }
