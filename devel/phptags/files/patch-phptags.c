--- src/phptags.c.orig	Wed May 26 08:21:25 2004
+++ src/phptags.c	Mon May 31 23:56:48 2004
@@ -48,6 +48,9 @@
 	int i,
 	    ch;
 
+	FILE *tmp_file;
+//	char *line = malloc(255);
+        
 	(void)read_config();
 	    
 	while ((ch = getopt(argc, argv, "cdf:hvV")) != -1) {
@@ -84,9 +87,6 @@
 	if (verbose && (current_conf != "none")) 
 		printf("Using config file: %s\n", current_conf);
 		
-	FILE *tmp_file;
-//	char *line = malloc(255);
-        
 	tmp_file = fopen(tagsfile, "w+");
 	
 	if ((int)tmp_file == NULL) {
@@ -101,8 +101,8 @@
 	for (i = 0; i < argc; i++) {
 		char *m = malloc(256);
 		char *line;
-	        line = m;
 		FILE *fd;
+	        line = m;
 		
 		fd = fopen(argv[i], "r");
 		if ((int)fd == NULL) {
@@ -132,11 +132,13 @@
 				if (!commented) {
 					if (!strncmp("function ", line, 9)) {
 						/* foo bar.c /^function foo($bar)$/; */
+						int func_name_len;
+						char *func_name;
 						line+=9;
 						line[strlen(line) - 1] = '\0';
 						
-						int func_name_len = strlen(line) - strlen(strstr(line, "("));
-						char *func_name = malloc(func_name_len);
+						func_name_len = strlen(line) - strlen(strstr(line, "("));
+						func_name = malloc(func_name_len);
 												
 						(void)memmove(func_name, line, func_name_len);
 						
@@ -148,11 +150,13 @@
 					
 						free(func_name);
 					} else if (!strncmp("class ", line, 6) && tag_classes == 1) {
+						int class_name_len;
+						char *class_name;
 						line+=6;
 						line[strlen(line) - 1] = '\0';
 
-						int class_name_len = strlen(line) - strlen(strstr(line, " "));
-						char *class_name = malloc(class_name_len);
+						class_name_len = strlen(line) - strlen(strstr(line, " "));
+						class_name = malloc(class_name_len);
 
 						(void)strncpy(class_name, line, class_name_len);
 						
