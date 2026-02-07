--- tools/qfcc/source/switch.c.orig	2013-01-23 03:10:55 UTC
+++ tools/qfcc/source/switch.c
@@ -383,6 +383,10 @@ switch_expr (switch_block_t *switch_bloc
 	int         saved_line = pr.source_line;
 	string_t    saved_file = pr.source_file;
 
+	if (switch_block->test->type == ex_error) {
+		return switch_block->test;
+	}
+
 	pr.source_line = sw_val->line = switch_block->test->line;
 	pr.source_file = sw_val->file = switch_block->test->file;
 
