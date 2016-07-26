--- macunpack/lzh.c.orig	1993-10-02 20:16:00 UTC
+++ macunpack/lzh.c
@@ -23,7 +23,7 @@ extern void de_lzah();
 extern unsigned char (*lzah_getbyte)();
 extern void de_lzh();
 
-typedef struct methodinfo {
+struct methodinfo {
 	char *name;
 	int number;
 };
@@ -40,13 +40,13 @@ static struct methodinfo methods[] = {
     {"-lzs-", lzs}
 };
 static char *lzh_archive;
-static char *lzh_pointer;
-static char *lzh_data;
-static char *lzh_finfo;
-static int lzh_fsize;
-static int lzh_kind;
+char *lzh_pointer;
+char *lzh_data;
+char *lzh_finfo;
+int lzh_fsize;
+int lzh_kind;
 static int oldsize;
-static char *lzh_file;
+char *lzh_file;
 static int lzh_filesize;
 static char *lzh_current;
 static char *tmp_out_ptr;
