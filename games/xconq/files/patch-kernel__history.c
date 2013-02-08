--- kernel/history.c.orig
+++ kernel/history.c
@@ -190,7 +190,7 @@
 		&& find_event_type(pattern) == hevt->type) {
 		text = cadr(head);
 		if (stringp(text)) {
-		    sprintf(abuf, c_string(text));
+		    sprintf(abuf, "%s", c_string(text));
 		} else {
 		    sprintlisp(abuf, text, 50);
 		}
