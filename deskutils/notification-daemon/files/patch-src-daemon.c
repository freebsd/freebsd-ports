diff -Naur notification-daemon-0.3.5.orig/src/daemon.c notification-daemon-0.3.5/src/daemon.c
--- src/daemon.c	2006-04-26 10:32:50.000000000 +0200
+++ src/daemon.c	2006-06-18 05:07:47.000000000 +0200
@@ -399,14 +399,54 @@
 	GValueArray *image_struct;
 	GValue *value;
 	GArray *tmp_array;
+	GType type = G_VALUE_TYPE (icon_data); 
+  
+	static const GType types[] = {
+	    G_TYPE_INT,
+	    G_TYPE_INT,
+	    G_TYPE_INT,
+	    G_TYPE_BOOLEAN,
+	    G_TYPE_INT,
+	    G_TYPE_INT
+	};
+
+
+	if (dbus_g_type_is_struct (type))
+	{
+	    int n;
+
+	    if (dbus_g_type_get_struct_size (type) < 7)
+	    {
+		g_warning("_notify_daemon_process_icon_data expected 7 data members, got only %d", dbus_g_type_get_struct_size (type)); 
+		return FALSE;
+	    }
+
+	    for (n = 0; n < G_N_ELEMENTS (types); ++n)
+	    {
+		GType check = dbus_g_type_get_struct_member_type (type, n);
+		if (check != types[n])
+		{
+		    g_warning("_notify_daemon_process_icon_data expected '%s' at position %d, but got '%s'",
+			      g_type_name (types[n]), n, g_type_name (check)); 
+		    return FALSE;
+		}
 
-	if (!G_VALUE_HOLDS(icon_data, G_TYPE_VALUE_ARRAY))
+		/* We must check this separately as it's not a constant and can't be part of the types[] array */
+		if (dbus_g_type_get_struct_member_type (type, 6) != DBUS_TYPE_G_UCHAR_ARRAY) 
+		{
+		    g_warning("_notify_daemon_process_icon_data expected '%s' at position %d, but got '%s'",
+			      g_type_name (DBUS_TYPE_G_UCHAR_ARRAY), 6, g_type_name (dbus_g_type_get_struct_member_type (type,6))); 
+		    return FALSE;
+		}
+	    }
+	}
+	else
 	{
-		g_warning("_notify_daemon_process_icon_data expected a "
-				  "GValue of type GValueArray");
-		return FALSE;
+	    g_warning("_notify_daemon_process_icon_data got wrong data"); 
+	    return FALSE;
 	}
 
+
 	image_struct = (GValueArray *)g_value_get_boxed(icon_data);
 	value = g_value_array_get_nth(image_struct, 0);
 
