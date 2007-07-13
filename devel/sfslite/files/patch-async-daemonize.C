--- async/daemonize.C.orig	2005-11-01 16:20:30.000000000 +0000
+++ async/daemonize.C	2007-07-12 22:38:51.000000000 +0000
@@ -49,18 +49,18 @@
 	      const str &logfile, int flags, mode_t mode)
 {
 #ifdef PATH_LOGGER
-  char *av[] = { PATH_LOGGER, "-p", NULL, "-t", NULL, NULL, NULL };
+  char *av[] = { (char *)PATH_LOGGER, (char *)"-p", NULL, (char *)"-t", NULL, NULL, NULL };
   av[2] = const_cast<char *> (priority.cstr ());
   
   if (line)
     av[5] = const_cast<char *> (line.cstr ());
   else
-    av[5] = "log started";
+    av[5] = (char *)"log started";
 
   if (tag)
     av[4] = const_cast<char *> (tag.cstr ());
   else 
-    av[4] = "";
+    av[4] = (char *)"";
 
   pid_t pid;
   int status;
@@ -93,9 +93,9 @@
 start_logger ()
 {
 #ifdef PATH_LOGGER
-  char *av[] = { PATH_LOGGER, "-p",
+  char *av[] = { (char *)PATH_LOGGER, (char *)"-p",
 		 const_cast<char *> (syslog_priority.cstr ()),
-		 "-t", "", NULL};
+		 (char *)"-t", (char *)"", NULL};
   int fds[2];
 
   close (0);
@@ -177,7 +177,7 @@
       piddir = builddir;
     str path = strbuf () << piddir << "/" << progname << ".pid";
     struct stat sb;
-    if (str2file (path, strbuf ("%d\n", int (getpid ())), 0444, &sb))
+    if (str2file (path, strbuf ("%d\n", int (getpid ())), 0444, false, &sb))
       pidfiles.push_back (pidfile (path, sb));
   }
 }
