--- src/cli.c.orig	2016-08-01 07:59:32 UTC
+++ src/cli.c
@@ -267,9 +267,9 @@ static int			s_fd = -1;
 static char			*appl = NULL;
 static int			run_after = 0;
 static char			*rootdir = NULL;
-static char			*compiler_c = "gcc";
-static char			*compiler_cpp = "g++";
-static char			*compiler_ld = "gcc";
+static char			*compiler_c = "cc";
+static char			*compiler_cpp = "c++";
+static char			*compiler_ld = "cc";
 static struct cfile_list	source_files;
 static struct buildopt_list	build_options;
 static int			source_files_count;
