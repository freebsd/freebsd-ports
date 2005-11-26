--- src/config.cpp.orig	Fri Nov  7 18:59:01 2003
+++ src/config.cpp	Fri Nov 25 03:54:00 2005
@@ -30,6 +30,11 @@
 void load_config(char *file, CONFIG *conf) {
 
 	FILE *f = fopen(file, "rt");
+	if(!f) {
+		// Try default config first
+		file = DEFAULT_CONFIG_FILE;
+		f = fopen(file, "rt");
+	}
 	if(!f)
 		error_msg("Unable to load config file: %s!", file);
 
