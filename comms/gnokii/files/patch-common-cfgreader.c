--- common/cfgreader.c.orig	2011-12-02 14:53:04 UTC
+++ common/cfgreader.c
@@ -991,7 +991,7 @@ static bool cfg_get_log_target(gn_log_ta
 #define CHECK_SIZE()	if (*retval >= size) { \
 	void *aux; \
 	size *= 2; \
-	aux = realloc(config_file_locations, size); \
+	aux = realloc(config_file_locations, size * sizeof(char *)); \
 	if (aux) \
 		config_file_locations = aux; \
 	else {\
@@ -1107,7 +1107,7 @@ static char **get_locations(int *retval)
 		if (i >= xcd_size) {
 			void *aux;
 			xcd_size *= 2;
-			aux = realloc(xdg_config_dir, xcd_size);
+			aux = realloc(xdg_config_dir, xcd_size * sizeof(char *));
 			if (aux)
 				xdg_config_dir = aux;
 			else {
