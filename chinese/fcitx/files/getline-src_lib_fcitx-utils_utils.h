--- ./src/lib/fcitx-utils/utils.h~	2011-10-02 05:43:11.000000000 -0500
+++ ./src/lib/fcitx-utils/utils.h	2011-11-09 14:43:09.006406004 -0600
@@ -120,6 +120,8 @@ extern "C" {
 
     char* fcitx_get_process_name();
 
+	ssize_t getline(char ** linep, size_t * linecapp, FILE * stream);
+
 #ifdef __cplusplus
 }
 #endif
