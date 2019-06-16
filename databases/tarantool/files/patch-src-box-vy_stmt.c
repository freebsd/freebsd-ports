Obtained from:	https://github.com/tarantool/tarantool/commit/518557963250fd30b22005376feb4e0e2a6786a1

--- src/box/vy_stmt.c.orig
+++ src/box/vy_stmt.c
@@ -447,18 +447,19 @@ vy_stmt_new_surrogate_delete_raw(struct tuple_format *format,
 	struct tuple_field *field;
 	struct json_token *parent = &format->fields.root;
 	while (true) {
-		int idx;
-		while ((idx = mp_stack_advance(&stack)) == -1) {
+		struct mp_frame *frame = mp_stack_top(&stack);
+		while (!mp_frame_advance(frame)) {
 			mp_stack_pop(&stack);
 			if (mp_stack_is_empty(&stack))
 				goto finish;
+			frame = mp_stack_top(&stack);
 			parent = parent->parent;
 		}
 		struct json_token token;
-		switch (mp_stack_type(&stack)) {
+		switch (frame->type) {
 		case MP_ARRAY:
 			token.type = JSON_TOKEN_NUM;
-			token.num = idx;
+			token.num = frame->idx;
 			break;
 		case MP_MAP:
 			if (mp_typeof(*src_pos) != MP_STR) {
