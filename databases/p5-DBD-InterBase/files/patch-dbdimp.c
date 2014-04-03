--- dbdimp.c.orig	2008-01-08 09:02:45.000000000 +0300
+++ dbdimp.c		2014-01-27 13:58:49.202445490 +0400
@@ -113,7 +113,7 @@
 
     if (DBIc_TRACE_LEVEL(imp_xxh) >= 2)
         PerlIO_printf(DBIc_LOGPIO(imp_xxh), "%s error %d recorded: %s\n", 
-            what, rc, SvPV(errstr,na));
+            what, rc, SvPV(errstr,PL_na));
 }
 
 #define CALC_AVAILABLE(buff) sizeof(buff) - strlen(buff) - 1
@@ -693,7 +693,7 @@
         return Nullsv;
     else
     {
-        if ((result == &sv_yes) || (result == &sv_no))
+        if ((result == &PL_sv_yes) || (result == &PL_sv_no))
             return result;
         else
             return sv_2mortal(result);
@@ -1991,8 +1991,8 @@
         DBIh_EVENT2(drh, ERROR_event, DBIc_ERR(imp_drh), DBIc_ERRSTR(imp_drh));
         return FALSE;
     }
-    if (perl_destruct_level)
-        perl_destruct_level = 0;
+    if (PL_perl_destruct_level)
+        PL_perl_destruct_level = 0;
     return FALSE;
 }

