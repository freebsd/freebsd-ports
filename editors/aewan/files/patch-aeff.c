--- aeff.c.orig	2005-10-01 01:50:41 UTC
+++ aeff.c
@@ -187,11 +187,12 @@ void aeff_write_header(AeFile *f, const 
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
