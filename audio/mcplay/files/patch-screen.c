--- screen.c.orig	2002-04-28 13:30:35 UTC
+++ screen.c
@@ -275,9 +275,13 @@ void screen_message( ScreenData *data, g
    gchar *tmp, *str;
    
    va_start(az, fmt);
-   str = g_strdup_vprintf(fmt, az);
+   if ( fmt != NULL )
+      str = g_strdup_vprintf(fmt, az);
    va_end(az);
    
+   if ( fmt == NULL )
+      return;
+
    if( data->nmsg >= 0 )
    {
       tmp = g_strdup_printf("%*.*s", -1*(data->cols-7), data->cols-7, str);
