--- src/eb.c.orig	Mon Nov 18 18:13:06 2002
+++ src/eb.c	Mon Feb 24 02:06:33 2003
@@ -24,6 +24,7 @@
 #include <iconv.h>
 #include <langinfo.h>
 #include <wchar.h>
+#include <pthread.h>
 
 
 #define MAX_HITS            50
@@ -1746,7 +1747,8 @@
 	DICT_GROUP *group;
 	char word[65535];
 
-	strcpy(word, arg);
+	strncpy(word, arg, sizeof(word)-1);
+	word[sizeof(word)-1] = '\0';
 
 	group_item = g_list_first(group_list);
 	while(group_item != NULL){
@@ -1854,15 +1856,19 @@
 {
 	gint rc;
 	gint method;
+	pthread_attr_t thread_attr;
 
 	thread_running = 1;
 	hit_count = 0;
-	rc = pthread_create(&tid, NULL, ebook_search_thread, (void *)word);
+
+	pthread_attr_init(&thread_attr);
+	pthread_attr_setstacksize(&thread_attr, 256*1024);
+	rc = pthread_create(&tid, &thread_attr, ebook_search_thread, (void *)word);
 	if(rc != 0){
 		perror("pthread_create");
 		exit(1);
 	}
-
+	pthread_attr_destroy(&thread_attr);
 
 	method = ebook_search_method();
 	if(method == SEARCH_METHOD_FULL_TEXT){
