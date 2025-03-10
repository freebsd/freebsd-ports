--- io/mmap.c.orig	2015-07-24 04:28:04 UTC
+++ io/mmap.c
@@ -575,6 +575,7 @@ mwrite_f(
 	return 0;
 }
 
+#ifdef __linux__
 static void
 mremap_help(void)
 {
@@ -634,6 +635,7 @@ mremap_f(
 
 	return 0;
 }
+#endif
 
 void
 mmap_init(void)
@@ -689,6 +691,7 @@ mmap_init(void)
 		_("writes data into a region in the current memory mapping");
 	mwrite_cmd.help = mwrite_help;
 
+#ifdef __linux__
 	mremap_cmd.name = "mremap";
 	mremap_cmd.altname = "mrm";
 	mremap_cmd.cfunc = mremap_f;
@@ -699,11 +702,14 @@ mmap_init(void)
 	mremap_cmd.oneline =
 		_("alters the size of the current memory mapping");
 	mremap_cmd.help = mremap_help;
+#endif
 
 	add_command(&mmap_cmd);
 	add_command(&mread_cmd);
 	add_command(&msync_cmd);
 	add_command(&munmap_cmd);
 	add_command(&mwrite_cmd);
+#ifdef __linux__
 	add_command(&mremap_cmd);
+#endif
 }
