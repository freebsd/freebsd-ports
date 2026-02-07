--- tio.h.orig	2016-10-16 14:22:45 UTC
+++ tio.h
@@ -111,7 +111,7 @@ extern struct t_keynames_s {
   char *name;
 } t_keynames[];
 
-void (*error_msg)( const char *, ... ) __printflike(1, 2);
+extern void (*error_msg)( const char *, ... ) __printflike(1, 2);
   /* Pointer to the error message function.
    */
 
