--- libftp-5.0.1.modified.by.in/FtpStat.c.orig	Fri Sep 30 15:44:08 2005
+++ libftp-5.0.1.modified.by.in/FtpStat.c	Fri Sep 30 15:46:43 2005
@@ -84,6 +84,7 @@
   register FILE *in;
   register FTP_STAT *stat=NULL, *prev=NULL;
   register int sys_unix,sys_vms,sys_msdos;
+  int fd;
   
   *first = NULL;
   strcpy(syst,FtpSyst(ftp));
@@ -94,22 +95,28 @@
 
 #if ! defined( _WIN32 )
   sprintf(tmp,"/tmp/%s.XXXXXX",getpwuid(getuid())->pw_name);
-  if ( mktemp( tmp ) == -1 ) return EXIT( ftp, LQUIT );
+  if ( ( fd = mkstemp( tmp ) ) == -1 ) return EXIT( ftp, LQUIT );
+  close( fd );
 #else
 	sprintf( tmp, "extract-xiso.tmp.XXXXXX" );
 	if ( _mktemp( tmp ) == NULL ) return EXIT( ftp, LQUIT );
 #endif
 
-	if ( ( tmp2 = strdup( tmp ) ) == NULL ) { errno = ENOMEM; return EXIT( ftp, LQUIT ); }
+        if ( ( tmp2 = strdup( tmp ) ) == NULL ) {
+            errno = ENOMEM;
+            unlink( tmp );
+            return EXIT( ftp, LQUIT );
+        }
 
   if (*patern==0)
     FtpRetr(ftp,"LIST","",tmp);
   else
     FtpRetr(ftp,sys_unix?"LIST -d %s":"LIST %s",patern,tmp);
   
-  if ( (in=fopen(tmp,"r")) == NULL)
-    return EXIT(ftp,LQUIT);
-
+  if ( (in=fopen(tmp,"r")) == NULL) {
+      unlink( tmp );
+      return EXIT(ftp,LQUIT);
+  }
   
   while(1)
     {
