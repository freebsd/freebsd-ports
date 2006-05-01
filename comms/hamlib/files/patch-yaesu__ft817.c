--- yaesu/ft817.c.orig	Tue Apr 18 23:15:31 2006
+++ yaesu/ft817.c	Tue Apr 18 23:16:15 2006
@@ -288,8 +288,6 @@
 	.get_tone =             NULL,
 	.set_ctcss_tone = 	ft817_set_ctcss_tone,
 	.get_ctcss_tone = 	NULL,
-	.set_tone =             NULL,
-	.get_tone =             NULL,
 	.set_dcs_sql = 	        ft817_set_dcs_sql,
 	.get_dcs_sql =          NULL,
 	.set_tone_sql =         NULL,
