--- tools/dbus-send.c.orig	Sat Jul 16 17:31:11 2005
+++ tools/dbus-send.c	Sat Jul 16 17:31:30 2005
@@ -401,6 +401,7 @@
 
       if (container_type == DBUS_TYPE_DICT_ENTRY)
 	{
+	  char sig[5];
 	  arg = c;
 	  c = strchr (c, ':');
 	  if (c == NULL)
@@ -410,7 +411,6 @@
 	    }
 	  *(c++) = 0;
 	  secondary_type = type_from_name (arg);
-	  char sig[5];
 	  sig[0] = DBUS_DICT_ENTRY_BEGIN_CHAR;
 	  sig[1] = type;
 	  sig[2] = secondary_type;
