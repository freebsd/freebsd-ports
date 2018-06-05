Fix the build with libgit2 0.27.

Obtained from:	https://git.archlinux.org/svntogit/packages.git/commit/trunk/libgit2-0.27.0.diff?h=packages/libgit2-glib&id=5c8af6b8236ed9a108ad980899477cb50ffeb324
--- libgit2-glib/ggit-config.c.orig	2015-08-10 06:33:13 UTC
+++ libgit2-glib/ggit-config.c
@@ -295,6 +295,7 @@ ggit_config_add_file (GgitConfig      *config,
 	ret = git_config_add_file_ondisk (_ggit_native_get (config),
 	                                  path,
 	                                  (git_config_level_t)level,
+	                                  NULL,
 	                                  force);
 	g_free (path);
 
