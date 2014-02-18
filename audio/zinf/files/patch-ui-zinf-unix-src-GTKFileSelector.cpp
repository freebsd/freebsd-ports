--- ui/zinf/unix/src/GTKFileSelector.cpp.orig	2003-09-16 19:36:23.000000000 +0200
+++ ui/zinf/unix/src/GTKFileSelector.cpp	2014-02-18 17:46:56.364931015 +0100
@@ -25,7 +25,8 @@
 #include <unistd.h>
 #include <dirent.h>
 
-#if defined(solaris)                                                          
+#if defined(solaris) || defined(__FreeBSD__)                                                         
+#include <stdlib.h>
 #include <sys/types.h>                                                        
 #include <sys/param.h>         /* for MAXPATHLEN */                           
 #include <sys/stat.h>                                                         
