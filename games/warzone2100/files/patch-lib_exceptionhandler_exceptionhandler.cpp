--- lib/exceptionhandler/exceptionhandler.cpp.orig	2017-04-23 13:12:16 UTC
+++ lib/exceptionhandler/exceptionhandler.cpp
@@ -120,6 +120,7 @@ static LONG WINAPI windowsExceptionHandl
 
 // POSIX headers:
 # include <unistd.h>
+# include <errno.h>
 # include <fcntl.h>
 # include <time.h>
 # include <sys/types.h>
