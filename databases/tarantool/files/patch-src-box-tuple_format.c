Obtained from:	https://github.com/tarantool/tarantool/commit/518557963250fd30b22005376feb4e0e2a6786a1

--- src/box/tuple_format.c.orig
+++ src/box/tuple_format.c
@@ -850,8 +850,8 @@ tuple_field_map_create(struct tuple_format *format, const char *tuple,
 	struct tuple_field *field;
 	struct json_token *parent = &format->fields.root;
 	while (true) {
-		int idx;
-		while ((idx = mp_stack_advance(&stack)) == -1) {
+		struct mp_frame *frame = mp_stack_top(&stack);
+		while (!mp_frame_advance(frame)) {
 			/*
 			 * If the elements of the current frame
 			 * are over, pop this frame out of stack
@@ -863,6 +863,7 @@ tuple_field_map_create(struct tuple_format *format, const char *tuple,
 			mp_stack_pop(&stack);
 			if (mp_stack_is_empty(&stack))
 				goto finish;
+			frame = mp_stack_top(&stack);
 			parent = parent->parent;
 		}
 		/*
@@ -871,10 +872,10 @@ tuple_field_map_create(struct tuple_format *format, const char *tuple,
 		 * for the subsequent format::fields lookup.
 		 */
 		struct json_token token;
-		switch (mp_stack_type(&stack)) {
+		switch (frame->type) {
 		case MP_ARRAY:
 			token.type = JSON_TOKEN_NUM;
-			token.num = idx;
+			token.num = frame->idx;
 			break;
 		case MP_MAP:
 			if (mp_typeof(*pos) != MP_STR) {
