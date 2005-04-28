Index: src/init.c
===================================================================
RCS file: /pack/anoncvs/wget/src/init.c,v
retrieving revision 1.109
retrieving revision 1.110
diff -u -r1.109 -r1.110
--- src/init.c	2005/04/27 22:16:28	1.109
+++ src/init.c	2005/04/28 09:32:13	1.110
@@ -211,7 +211,9 @@
   { "proxyuser",	&opt.proxy_user,	cmd_string },
   { "quiet",		&opt.quiet,		cmd_boolean },
   { "quota",		&opt.quota,		cmd_bytes_large },
+#ifdef HAVE_SSL
   { "randomfile",	&opt.random_file,	cmd_file },
+#endif
   { "randomwait",	&opt.random_wait,	cmd_boolean },
   { "readtimeout",	&opt.read_timeout,	cmd_time },
   { "reclevel",		&opt.reclevel,		cmd_number_inf },
