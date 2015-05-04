# Origin: https://github.com/jonas/tig/commit/718c6e94fcc111e5607d6ca0bf3d15271adc0d97
# Subject: ui: fix crash due to out-of-bounds array access

--- src/ui.c.orig	2015-04-09 00:19:11 UTC
+++ src/ui.c
@@ -293,7 +293,7 @@ open_file_finder(const char *commit)
 	finder.keymap = get_keymap("search", STRING_SIZE("search")),
 	file_finder_update(&finder);
 	file_finder_draw(&finder);
-	if (read_prompt_incremental("Find file: ", FALSE, file_finder_input_handler, &finder))
+	if (read_prompt_incremental("Find file: ", FALSE, file_finder_input_handler, &finder) && finder.pos.lineno < finder.lines)
 		file = get_path(finder.line[finder.pos.lineno]->text);
 
 	file_finder_done(&finder);
