--- kernel/nlang.c.orig
+++ kernel/nlang.c
@@ -839,7 +839,7 @@
 	    && strcmp(end, "s'") != 0
 	    && strcmp(end, "z'") != 0)
 	  sprintf(past_unitbuf, "the ");
-	sprintf(past_unitbuf, side_adjective(side2));
+	sprintf(past_unitbuf, "%s", side_adjective(side2));
 	strcat(past_unitbuf, " ");
     }
     /* Now add the past_unit's unique description. */
@@ -1035,7 +1035,7 @@
 		&& find_event_type(pattern) == hevt->type) {
 		text = cadr(head);
 		if (stringp(text)) {
-		    sprintf(buf, c_string(text));
+		    sprintf(buf, "%s", c_string(text));
 		} else {
 		    sprintlisp(buf, text, 50);
 		}
@@ -1046,7 +1046,7 @@
 		       ) {
 		text = cadr(head);
 		if (stringp(text)) {
-		    sprintf(buf, c_string(text));
+		    sprintf(buf, "%s", c_string(text));
 		} else {
 		    event_desc_from_list(side, text, hevt, buf);
 		}
