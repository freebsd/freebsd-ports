--- unarj-2.65.orig/unarj.c
+++ unarj.c
@@ -235,6 +235,8 @@ static UCRC   crctable[UCHAR_MAX + 1];
 
 /* Functions */
 
+void copy_path_relative(char *dest, char *src, size_t len);
+
 static void
 make_crctable()
 {
@@ -738,11 +740,11 @@ extract()
 
     no_output = 0;
     if (command == 'E')
-        strncopy(name, &filename[entry_pos], sizeof(name));
+        copy_path_relative(name, &filename[entry_pos], sizeof(name));
     else
     {
         strcpy(name, DEFAULT_DIR);
-        strncopy(name+strlen(name), filename, sizeof(name)-strlen(name));
+        copy_path_relative(name+strlen(name), filename, sizeof(name)-strlen(name));
     }
 
     if (host_os != OS)
