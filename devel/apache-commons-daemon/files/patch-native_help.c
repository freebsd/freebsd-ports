--- native/help.c.orig	2025-01-06 00:00:00 UTC
+++ native/help.c
@@ -123,6 +123,8 @@ void help(home_data *data)
     printf("        Refer java help for possible values.\n");
     printf("    --enable-preview\n");
     printf("        Java 11 --enable-preview option. Passed as it is to JVM\n");
+    printf("    --enable-native-access=<module name>\n");
+    printf("        Java 21 --enable-native-access option. Passed as it is to JVM\n");
     printf("\njsvc (Apache Commons Daemon) " JSVC_VERSION_STRING "\n");
     printf("Copyright (c) 1999-2025 Apache Software Foundation.\n");
 
