--- macunpack/lzh.c.orig	Thu Sep 28 13:10:04 2006
+++ macunpack/lzh.c	Thu Sep 28 13:11:27 2006
@@ -40,13 +40,13 @@
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
