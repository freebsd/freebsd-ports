--- src/transport.hxx.orig	Wed Jan 21 12:52:37 2004
+++ src/transport.hxx	Wed Jan 21 12:53:43 2004
@@ -386,7 +386,7 @@
     Scsi_Command(int f)
     {	char pass[32];	// periph_name is 16 chars long
 
-	cam=NULL, fd=-1, autoclose=1, filename=NULL;
+	cam=NULL, fd=fd, autoclose=1, filename=NULL;
 
 	memset (&ccb,0,sizeof(ccb));
 	ccb.ccb_h.func_code = XPT_GDEVLIST;
