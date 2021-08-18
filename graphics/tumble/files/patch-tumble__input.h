--- tumble_input.h.orig	2021-08-17 12:36:31 UTC
+++ tumble_input.h
@@ -71,4 +71,4 @@ void init_jpeg_handler (void);
 void init_pbm_handler  (void);
 void init_png_handler  (void);
 
-input_handler_t blank_handler;
+extern input_handler_t blank_handler;
