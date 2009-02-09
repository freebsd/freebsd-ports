--- mono/metadata/marshal.c.orig	2008-12-19 17:11:03.000000000 -0300
+++ mono/metadata/marshal.c	2009-01-04 12:43:13.000000000 -0300
@@ -1022,8 +1022,7 @@
 mono_string_builder_to_utf8 (MonoStringBuilder *sb)
 {
 	GError *error = NULL;
-	glong *res;
-	gchar *tmp;
+	gchar *tmp, *res = NULL;
 
 	if (!sb)
 		return NULL;
@@ -1037,14 +1036,12 @@
 		sb->cached_str = NULL;
 	}
 
-	res = mono_marshal_alloc (mono_stringbuilder_capacity (sb) + 1);
-
-	tmp = g_utf16_to_utf8 (mono_string_chars (sb->str), sb->length, NULL, res, &error);
+	tmp = g_utf16_to_utf8 (mono_string_chars (sb->str), sb->length, NULL, NULL, &error);
 	if (error) {
 		g_error_free (error);
-		mono_marshal_free (res);
 		mono_raise_exception (mono_get_exception_execution_engine ("Failed to convert StringBuilder from utf16 to utf8"));
 	} else {
+		res = mono_marshal_alloc (mono_stringbuilder_capacity (sb) + 1);
 		memcpy (res, tmp, sb->length + 1);
 		g_free (tmp);
 	}
