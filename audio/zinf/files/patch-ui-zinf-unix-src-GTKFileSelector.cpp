--- ui/zinf/unix/src/GTKFileSelector.cpp.orig	Wed Feb 19 16:39:23 2003
+++ ui/zinf/unix/src/GTKFileSelector.cpp	Sat Sep 13 03:02:14 2003
@@ -25,7 +25,7 @@
 #include <unistd.h>
 #include <dirent.h>
 
-#if defined(solaris)                                                          
+#if defined(solaris) || defined(__FreeBSD__)                                                         
 #include <sys/types.h>                                                        
 #include <sys/param.h>         /* for MAXPATHLEN */                           
 #include <sys/stat.h>                                                         
