--- camel-object.c.orig	Wed Oct 18 15:53:34 2006
+++ camel-object.c	Wed Oct 18 15:55:01 2006
@@ -457,7 +457,7 @@
 		}
 		
 		/* we batch up the properties and set them in one go */
-		if (!(argv = g_try_malloc ((gulong)(sizeof (*argv) + (count - CAMEL_ARGV_MAX) * sizeof (argv->argv[0])))))
+		if (!(argv = g_try_malloc ((guint32)(sizeof (*argv) + (count - CAMEL_ARGV_MAX) * sizeof (argv->argv[0])))))
 			return -1;
 		
 		argv->argc = 0;
@@ -537,8 +537,8 @@
 
 	count = g_slist_length(props);
 
-	arggetv = g_malloc0(sizeof(*arggetv) + (count - CAMEL_ARGV_MAX) * sizeof(arggetv->argv[0]));
-	argv = g_malloc0(sizeof(*argv) + (count - CAMEL_ARGV_MAX) * sizeof(argv->argv[0]));
+	arggetv = g_malloc0((guint32)(sizeof(*arggetv) + (count - CAMEL_ARGV_MAX) * sizeof(arggetv->argv[0])));
+	argv = g_malloc0((guint32)(sizeof(*argv) + (count - CAMEL_ARGV_MAX) * sizeof(argv->argv[0])));
 	l = props;
 	i = 0;
 	while (l) {
