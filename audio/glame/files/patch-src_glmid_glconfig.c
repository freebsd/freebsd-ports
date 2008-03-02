--- src/glmid/glconfig.c.orig	2008-03-02 14:05:46.000000000 -0500
+++ src/glmid/glconfig.c	2008-03-02 14:06:23.000000000 -0500
@@ -125,7 +125,8 @@ int glame_config_get_long(const char *ke
 	snprintf(cmd, 255, "(glame-config-get '%s)", key);
 	/* FIXME: execute with catch. */
 	s_res = glame_gh_safe_eval_str(cmd);
-	if (!gh_exact_p(s_res))
+	if (!gh_number_p(s_res)
+	    || !gh_exact_p(s_res))
 		return -1;
 	*value = glame_scm2long(s_res);
 	return 0;
