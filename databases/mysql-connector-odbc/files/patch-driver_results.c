--- driver/results.c.orig	2008-04-11 01:58:44.000000000 -0800
+++ driver/results.c	2009-01-08 11:46:27.000000000 -0900
@@ -1248,7 +1248,7 @@
                                        SQLROWOFFSET         irow,
                                        SQLULEN             *pcrow,
                                        SQLUSMALLINT FAR    *rgfRowStatus,
-                                       bool                 upd_status )
+                                       my_bool                 upd_status )
 {
     ulong rows_to_fetch;
     long cur_row, max_row;
