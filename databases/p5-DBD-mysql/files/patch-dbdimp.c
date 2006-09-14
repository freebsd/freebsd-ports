#
# Fix build with old gcc
#
--- dbdimp.c.orig	Fri Sep  8 17:25:59 2006
+++ dbdimp.c	Thu Sep 14 10:31:47 2006
@@ -2347,6 +2347,7 @@
   char *table;
   char *salloc;
   int htype;
+  my_ulonglong rows= 0;
 
   /* thank you DBI.c for this info! */
   D_imp_xxh(h);
@@ -2386,8 +2387,6 @@
                        params,
                        num_params,
                        imp_dbh->bind_type_guessing);
-
-  my_ulonglong rows= 0;
 
   if (dbis->debug >= 2)
     PerlIO_printf(DBILOGFP, "mysql_st_internal_execute\n");
