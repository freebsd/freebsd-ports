--- dbdimp.c	2004/02/25 04:38:03	1.105
+++ dbdimp.c	2004/03/03 11:26:48	1.106
@@ -1,5 +1,5 @@
 /*
-   $Id: dbdimp.c,v 1.105 2004/02/25 04:38:03 edpratomo Exp $
+   $Id: dbdimp.c,v 1.106 2004/03/03 11:26:48 edpratomo Exp $
 
    Copyright (c) 1999-2004  Edwin Pratomo
    Portions Copyright (c) 2001-2003  Daniel Ritz
@@ -2185,7 +2185,7 @@
             DBI_TRACE(1, (DBILOGFP, "ib_fill_isqlda: SQL_VARYING\n"));
         {
             char buf[25]; /* long long can have max 20 chars. */
-            char *tmp;
+            char *tmp = NULL;
             if (ivar->sqldata == (char *) NULL)
             {
                 if ((ivar->sqldata = (char *)safemalloc(
@@ -2204,7 +2204,7 @@
                 tmp = buf;
                 len = sprintf(tmp, "%ld", SvNV(value));
             }
-            else if (SvPOK(value)) {
+            else if (SvPOK(value) || (SvTYPE(value) == SVt_PVMG)) {
                 len = SvCUR(value);
                 tmp = SvPV_nolen(value);
             }
@@ -2261,7 +2261,7 @@
                 tmp = buf;
                 len = sprintf(tmp, "%ld", SvNV(value));
             }
-            else if (SvPOK(value)) {
+            else if (SvPOK(value) || (SvTYPE(value) == SVt_PVMG)) {
                 len = SvCUR(value);
                 tmp = SvPV_nolen(value);
             }
