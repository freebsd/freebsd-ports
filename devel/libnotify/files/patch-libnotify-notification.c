diff -Naur libnotify-0.4.2.orig/libnotify/notification.c libnotify-0.4.2/libnotify/notification.c
--- libnotify/notification.c	2006-06-15 11:14:03.000000000 +0200
+++ libnotify/notification.c	2006-06-18 05:09:08.000000000 +0200
@@ -901,7 +901,7 @@
 		return FALSE;
 	}
 
-	g_value_init(value, dbus_g_type_get_collection("GArray", G_TYPE_CHAR));
+	g_value_init(value, DBUS_TYPE_G_UCHAR_ARRAY); 
 	g_value_set_boxed_take_ownership(value, byte_array);
 	g_value_array_append(array, value);
 
@@ -961,7 +961,7 @@
 
 	value = g_new0(GValue, 1);
 	g_value_init(value, G_TYPE_VALUE_ARRAY);
-	g_value_set_boxed(value, image_struct);
+	g_value_set_boxed_take_ownership(value, image_struct);
 
 	g_hash_table_insert(notification->priv->hints,
 						g_strdup("icon_data"), value);
