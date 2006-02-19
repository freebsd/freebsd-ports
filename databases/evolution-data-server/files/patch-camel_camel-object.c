--- camel/camel-object.c.orig	Sun Feb 19 17:04:42 2006
+++ camel/camel-object.c	Sun Feb 19 17:06:06 2006
@@ -454,7 +454,7 @@ cobject_state_read(CamelObject *obj, FIL
 		}
 		
 		/* we batch up the properties and set them in one go */
-		if (!(argv = g_try_malloc (sizeof (*argv) + (count - CAMEL_ARGV_MAX) * sizeof (argv->argv[0]))))
+		if (!(argv = g_try_malloc ((guint32) (sizeof (*argv) + (count - CAMEL_ARGV_MAX) * sizeof (argv->argv[0])))))
 			return -1;
 		
 		argv->argc = 0;
@@ -534,8 +534,8 @@ cobject_state_write(CamelObject *obj, FI
 
 	count = g_slist_length(props);
 
-	arggetv = g_malloc0(sizeof(*arggetv) + (count - CAMEL_ARGV_MAX) * sizeof(arggetv->argv[0]));
-	argv = g_malloc0(sizeof(*argv) + (count - CAMEL_ARGV_MAX) * sizeof(argv->argv[0]));
+	arggetv = g_malloc0((guint32) (sizeof(*arggetv) + (count - CAMEL_ARGV_MAX) * sizeof(arggetv->argv[0])));
+	argv = g_malloc0((guint32) (sizeof(*argv) + (count - CAMEL_ARGV_MAX) * sizeof(argv->argv[0])));
 	l = props;
 	i = 0;
 	while (l) {
