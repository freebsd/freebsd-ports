--- dbdimp.c.orig	Thu Mar 22 10:30:12 2007
+++ dbdimp.c	Thu Mar 22 10:31:00 2007
@@ -3413,11 +3413,7 @@
   if (!imp_sth->result)
   {
     do_error(sth, JW_ERR_SEQUENCE, "fetch() without execute()"
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
              ,NULL);
-#else
-            );
-#endif
     return Nullav;
   }
 
@@ -3577,11 +3573,7 @@
       if (mysql_errno(&imp_dbh->mysql))
         do_error(sth, mysql_errno(&imp_dbh->mysql),
                  mysql_error(&imp_dbh->mysql)
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
                  , mysql_sqlstate(&imp_dbh->mysql));
-#else
-                );
-#endif
 
 
 #if MYSQL_VERSION_ID >= MULTIPLE_RESULT_SET_VERSION
@@ -3909,11 +3901,7 @@
   /* Are we asking for a legal value? */
   if (what < 0 ||  what >= AV_ATTRIB_LAST)
     do_error(sth, JW_ERR_NOT_IMPLEMENTED, "Not implemented"
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
              , NULL);
-#else
-              );
-#endif
 
   /* Return cached value, if possible */
   else if (cacheit  &&  imp_sth->av_attr[what])
@@ -3923,11 +3911,7 @@
   else if (!res)
     do_error(sth, JW_ERR_NOT_ACTIVE,
 	     "statement contains no result"
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
              ,NULL);
-#else
-            );
-#endif
   /* Do the real work. */
   else
   {
@@ -4238,11 +4222,7 @@
   {
     do_error(sth, JW_ERR_ILLEGAL_PARAM_NUM,
              "Illegal parameter number"
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
              , NULL);
-#else
-            );
-#endif
     return FALSE;
   }
 
@@ -4265,11 +4245,7 @@
               "Binding non-numeric field %d, value %s as a numeric!",
               param_num, neatsvpv(value,0));
       do_error(sth, JW_ERR_ILLEGAL_PARAM_NUM, err_msg
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
                ,NULL);
-#else
-                );
-#endif
     }
   }
 
@@ -4277,11 +4253,7 @@
   {
     do_error(sth, JW_ERR_NOT_IMPLEMENTED,
              "Output parameters not implemented"
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
              ,NULL);
-#else
-                );
-#endif
     return FALSE;
   }
 
@@ -4439,11 +4411,7 @@
   if (!my_login(h, imp_dbh))
   {
     do_error(h, mysql_errno(&imp_dbh->mysql), mysql_error(&imp_dbh->mysql)
-#if MYSQL_VERSION_ID >= SQL_STATE_VERSION
              , mysql_sqlstate(&imp_dbh->mysql));
-#else
-              );
-#endif
     memcpy (&imp_dbh->mysql, &save_socket, sizeof(save_socket));
     ++imp_dbh->stats.auto_reconnects_failed;
     return FALSE;
