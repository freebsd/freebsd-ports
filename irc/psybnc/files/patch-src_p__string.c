--- src/p_string.c.orig	2016-06-20 14:41:27 UTC
+++ src/p_string.c
@@ -616,7 +616,7 @@ int loadlanguage(char *langf)
     int msg;
     pcontext;
     clearlanguage();
-    ap_snprintf(lfname,sizeof(lfname),"lang/%s.lng",langf);
+    ap_snprintf(lfname,sizeof(lfname),"%s/lang/%s.lng",PSYBASE, langf);
     maxindex=0;
     langname[0]=0;
     lfile=fopen(lfname,"r");
