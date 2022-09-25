--- playtimidity/timidityconfig.c.orig	2022-09-25 19:16:16 UTC
+++ playtimidity/timidityconfig.c
@@ -293,7 +293,7 @@ static void refresh_configfiles (void)
 	}
 }
 
-static int timidityConfigInit (struct moduleinfostruct *info, struct ocpfilehandle_t *f, const struct cpifaceplayerstruct *)
+static int timidityConfigInit (struct moduleinfostruct *info, struct ocpfilehandle_t *f, const struct cpifaceplayerstruct *cpi)
 {
 	return 1;
 }
