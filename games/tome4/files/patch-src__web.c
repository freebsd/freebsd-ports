--- ./src/web.c.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./src/web.c	2014-06-04 12:40:26.927305671 -0400
@@ -517,7 +517,7 @@
 	char *spawnname = NULL;
 	char *libname = NULL;
 	const char *self = get_self_executable(g_argc, g_argv);
-#if defined(SELFEXE_LINUX) || defined(SELFEXE_BSD)
+#if defined(SELFEXE_LINUX)
 #if defined(TE4_RELPATH64)
 	const char *spawnbname = "cef3spawn64";
 	spawnname = malloc(strlen(self) + strlen(spawnbname) + 1);
