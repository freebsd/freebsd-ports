--- common/cfgreader.c.orig	2011-12-02 15:53:04.000000000 +0100
+++ common/cfgreader.c	2013-08-13 13:25:46.836652059 +0200
@@ -991,7 +991,7 @@
 #define CHECK_SIZE()	if (*retval >= size) { \
 	void *aux; \
 	size *= 2; \
-	aux = realloc(config_file_locations, size); \
+	aux = realloc(config_file_locations, size * sizeof(char *)); \
 	if (aux) \
 		config_file_locations = aux; \
 	else {\
@@ -1107,7 +1107,7 @@
 		if (i >= xcd_size) {
 			void *aux;
 			xcd_size *= 2;
-			aux = realloc(xdg_config_dir, xcd_size);
+			aux = realloc(xdg_config_dir, xcd_size * sizeof(char *));
 			if (aux)
 				xdg_config_dir = aux;
 			else {
