--- screen.c.orig	2010-03-18 19:50:01.000000000 -0700
+++ screen.c	2010-03-18 19:54:07.000000000 -0700
@@ -275,9 +275,13 @@
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
