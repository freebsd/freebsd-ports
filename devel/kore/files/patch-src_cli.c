--- src/cli.c.orig	2018-07-18 14:25:49 UTC
+++ src/cli.c
@@ -800,7 +800,7 @@ cli_info(int argc, char **argv)
 		printf("kore source  \t %s\n", bopt->kore_source);
 	} else {
 		cli_kore_features(bopt, &features, &len);
-		printf("kore binary  \t %s/bin/kore\n", prefix);
+		printf("kore binary  \t %s/bin/kore%%SUFFIX%%\n", prefix);
 		printf("kore features\t %.*s\n", (int)len, features);
 		free(features);
 	}
@@ -1537,7 +1537,7 @@ cli_run_kore(void)
 		(void)cli_vasprintf(&cmd, "./%s", appl);
 	} else {
 		flags = "-fnrc";
-		(void)cli_vasprintf(&cmd, "%s/bin/kore", prefix);
+		(void)cli_vasprintf(&cmd, "%s/bin/kore%%SUFFIX%%", prefix);
 		(void)cli_vasprintf(&cpath, "conf/%s.conf", appl);
 	}
 
@@ -1838,6 +1838,9 @@ cli_build_flags_common(struct buildopt *bopt, struct c
 	else
 		cli_buf_appendf(buf, "-I%s/include ", bopt->kore_source);
 
+
+	cli_buf_appendf(buf, "-I%%OPENSSLINC%% ");
+	cli_buf_appendf(buf, "-I%s/include/kore%%SUFFIX%% ", PREFIX);
 #if defined(__MACH__)
 	/* Add default openssl include path from homebrew / ports under OSX. */
 	cli_buf_appendf(buf, "-I/opt/local/include ");
@@ -1996,7 +1999,7 @@ cli_kore_features(struct buildopt *bopt, char **out, s
 	if (bopt->single_binary) {
 		(void)cli_vasprintf(&path, ".objs/features");
 	} else {
-		(void)cli_vasprintf(&path, "%s/share/kore/features", prefix);
+		(void)cli_vasprintf(&path, "%s/share/kore%%SUFFIX%%/features", prefix);
 	}
 
 	cli_file_open(path, O_RDONLY, &fd);
