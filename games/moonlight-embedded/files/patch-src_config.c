--- src/config.c.orig	2023-10-11 15:50:11 UTC
+++ src/config.c
@@ -42,6 +42,7 @@
 #define write_config_bool(fd, key, value) fprintf(fd, "%s = %s\n", key, value ? "true":"false")
 
 bool inputAdded = false;
+bool isNoSdl = false;
 
 static struct option long_options[] = {
   {"720", no_argument, NULL, 'a'},
@@ -49,6 +50,7 @@ static struct option long_options[] = {
   {"4k", no_argument, NULL, '0'},
   {"width", required_argument, NULL, 'c'},
   {"height", required_argument, NULL, 'd'},
+  {"nosdl", no_argument, NULL, 'e'},
   {"bitrate", required_argument, NULL, 'g'},
   {"packetsize", required_argument, NULL, 'h'},
   {"app", required_argument, NULL, 'i'},
@@ -149,6 +151,9 @@ static void parse_argument(int c, char* value, PCONFIG
     break;
   case 'd':
     config->stream.height = atoi(value);
+    break;
+  case 'e':
+    isNoSdl = true;
     break;
   case 'g':
     config->stream.bitrate = atoi(value);
