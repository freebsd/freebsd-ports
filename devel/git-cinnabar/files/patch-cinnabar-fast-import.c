Chase https://github.com/git/git/commit/8de7eeb54b6a

--- cinnabar-fast-import.c.orig	2017-01-18 08:05:01 UTC
+++ cinnabar-fast-import.c
@@ -83,9 +83,6 @@ static void init()
 	git_pack_config();
 	ignore_case = 0;
 
-	if (!pack_compression_seen && core_compression_seen)
-		pack_compression_level = core_compression_level;
-
 	alloc_objects(object_entry_alloc);
 	strbuf_init(&command_buf, 0);
 	atom_table = xcalloc(atom_table_sz, sizeof(struct atom_str*));
