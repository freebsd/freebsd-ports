--- ./examples/strings.c.orig	2013-02-22 17:04:18.476679318 +0000
+++ ./examples/strings.c	2013-02-22 17:04:45.041658118 +0000
@@ -39,7 +39,7 @@
 	cfustring_append(buf, "test^*string%2^*3");
 	strings = cfustring_split_to_c_str(buf, &num_strings, 0, "%", "^*", NULL);
 
-	printf("got back %u strings\n", num_strings);
+	printf("got back %zu strings\n", num_strings);
 
 	printf("\n");
 	for (i = 0; i < num_strings; i++) {
@@ -52,7 +52,7 @@
 	free(strings);
 
 	header_lines = cfustring_split(header_block, &num_headers, 0, "\r\n", "\n", NULL);
-	printf("got back %u headers\n", num_strings);
+	printf("got back %zu headers\n", num_strings);
 
 	for (i = 0; i < num_headers; i++) {
 		strings = cfustring_split_to_c_str(header_lines[i], &num_strings, 2, ":", NULL);
@@ -61,7 +61,7 @@
 			size_t j = 0;
 			for (j = 0; j < num_strings; j++) free(strings[j]);
 			free(strings);
-			fprintf(stderr, "bad header: %u strings from split -- '%s'\n", num_strings, cfustring_get_buffer(header_lines[i]));
+			fprintf(stderr, "bad header: %zu strings from split -- '%s'\n", num_strings, cfustring_get_buffer(header_lines[i]));
 			continue;
 		}
 
