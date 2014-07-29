--- sql/mysqld.cc.orig	Sat Aug  6 03:39:41 2005
+++ sql/mysqld.cc	Sun Aug 28 20:41:38 2005
@@ -3177,7 +3177,7 @@
   init_ssl();
 
 #ifdef HAVE_LIBWRAP
-  libwrapName= my_progname+dirname_length(my_progname);
+  libwrapName= (char *) my_progname+dirname_length(my_progname);
   openlog(libwrapName, LOG_PID, LOG_AUTH);
 #endif
 
