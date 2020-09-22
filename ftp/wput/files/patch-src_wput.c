--- src/wput.c.orig	2008-09-27 10:31:23 UTC
+++ src/wput.c
@@ -69,6 +69,7 @@ int  start_fsession();
 int  start_ftp();
 int  start_recur_ftp();
 void read_netrc_file(void);
+opt_t opt;
 
 int main(int argc, char *argv[]){
 #ifdef WIN32
