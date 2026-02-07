--- speech_tools/siod/editline.c.orig	2020-08-24 09:52:13 UTC
+++ speech_tools/siod/editline.c
@@ -73,7 +73,7 @@
 /* modified by awb to allow specifcation of history size at run time  */
 /* (though only once)                                                 */
 int editline_histsize=256;
-char *editline_history_file;
+extern char *editline_history_file;
 /* If this is defined it'll be called for completion first, before the */
 /* internal file name completion will be                               */
 EL_USER_COMPLETION_FUNCTION_TYPE*el_user_completion_function = NULL;
