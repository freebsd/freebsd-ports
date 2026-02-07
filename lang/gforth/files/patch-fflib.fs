--- fflib.fs.orig	2013-10-11 21:31:28 UTC
+++ fflib.fs
@@ -37,7 +37,7 @@ s" callback" add-lib
 \c typedef void *Label;
 \c typedef Label *Xt;
 \c 
-\c void gforth_callback_ffcall(Xt* fcall, void * alist)
+\c void gforth_callback_ffcall(void* fcall, va_alist alist)
 \c {
 \c #ifndef HAS_BACKLINK
 \c   void **gforth_pointers = saved_gforth_pointers;
