--- aeff.c.orig	Wed Aug 11 10:04:50 2004
+++ aeff.c	Thu Sep  2 23:56:24 2004
@@ -187,11 +187,12 @@
 static bool aeff_read_mark(AeFile *f, const char *mark_name, char pref) {
    char *line;
    char *s;
-   zfree(&err_string);
 
    autod_begin;
    autod_register(line, free);
    
+   zfree(&err_string);
+
    autod_assign(line, freadline_ex(f->f, gzgetc));
 
    /* if EOF was reached before anything could be read, something is wrong */
