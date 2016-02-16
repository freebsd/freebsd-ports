--- conf.c.orig	2015-10-08 19:14:23 UTC
+++ conf.c
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
