--- src/config.h.orig	2023-10-11 15:50:11 UTC
+++ src/config.h
@@ -51,6 +51,7 @@ typedef struct _CONFIGURATION {
 } CONFIGURATION, *PCONFIGURATION;
 
 extern bool inputAdded;
+extern bool isNoSdl;
 
 bool config_file_parse(char* filename, PCONFIGURATION config);
 void config_parse(int argc, char* argv[], PCONFIGURATION config);
