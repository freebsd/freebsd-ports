--- src/jni/org_gnu_gconf_ConfValue.c.orig	Thu Feb 19 16:19:17 2004
+++ src/jni/org_gnu_gconf_ConfValue.c	Thu Feb 19 16:19:46 2004
@@ -111,8 +111,9 @@
 	jclass aCls = NULL;
 	guint len;
 	jobjectArray ar;
+	GConfValueType vt;
 	len = g_slist_length(list);
-	GConfValueType vt = gconf_value_get_list_type((GConfValue*)value);
+	vt = gconf_value_get_list_type((GConfValue*)value);
 	if (vt == GCONF_VALUE_STRING)
 		aCls = (*env)->FindClass(env, "java/lang/String");
 	else if (vt == GCONF_VALUE_INT)
