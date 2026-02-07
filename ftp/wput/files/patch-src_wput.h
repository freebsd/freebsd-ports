--- src/wput.h.orig	2008-09-27 10:31:23 UTC
+++ src/wput.h
@@ -79,7 +79,7 @@ typedef struct _password_list {
   struct _password_list * next;
 } password_list;
 
-struct global_options {
+typedef struct global_options {
   char * sbuf;
   int sbuflen;
   unsigned int bindaddr;
@@ -140,7 +140,9 @@ struct global_options {
 
   unsigned short int retry_interval;
   unsigned       int speed_limit;
-} opt;
+} opt_t;
+
+extern opt_t opt;
 
 extern _fsession * fsession_queue_entry_point;
 extern char * email_address;
