 #ifndef SSLSEC
--- ./src/p_string.c	Fri Jul 19 09:01:52 2002
+++ ../../psybnc.mina/src/p_string.c	Sun Nov 24 17:58:56 2002
@@ -613,7 +613,7 @@
     int msg;
     pcontext;
     clearlanguage();
-    ap_snprintf(lfname,sizeof(lfname),"lang/%s.lng",langf);
+    ap_snprintf(lfname,sizeof(lfname),"%s/lang/%s.lng",PSYBASE, langf);
     maxindex=0;
     langname[0]=0;
     lfile=fopen(lfname,"r");
