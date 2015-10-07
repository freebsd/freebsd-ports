--- conf.c.orig	2015-01-16 16:26:23.872241677 -0600
+++ conf.c	2015-01-16 16:27:00.595237894 -0600
@@ -321,7 +321,11 @@ conf_create(void)
 	conf->read_only = false;
 	conf->read_only_direct = false;
 	conf->recache = false;
+#if 1
+	conf->run_second_cpp = true;
+#else
 	conf->run_second_cpp = false;
+#endif
 	conf->sloppiness = 0;
 	conf->stats = true;
 	conf->temporary_dir = x_strdup("");
