--- src/main.c.orig	2021-12-20 00:24:48 UTC
+++ src/main.c
@@ -258,12 +244,8 @@ int main(int argc, char* argv[]) {
       exit(-1);
     }
     config.address[0] = 0;
-    printf("Searching for server...\n");
-    gs_discover_server(config.address);
-    if (config.address[0] == 0) {
-      fprintf(stderr, "Autodiscovery failed. Specify an IP address next time.\n");
-      exit(-1);
-    }
+    fprintf(stderr, "Autodiscovery unsupported. Specify an IP address next time.\n");
+    exit(-1);
   }
 
   char host_config_file[128];
