$FreeBSD$

Index: ../ecos/host/tools/Utils/common/eCosStd.h
===================================================================
RCS file: /home/tg/cvs/ecos/host/tools/Utils/common/eCosStd.h,v
retrieving revision 1.1.1.1
diff -u -r1.1.1.1 eCosStd.h
--- host/tools/Utils/common/eCosStd.h	22 Aug 2003 11:37:35 -0000	1.1.1.1
+++ host/tools/Utils/common/eCosStd.h	6 Sep 2003 16:24:17 -0000
@@ -116,7 +116,6 @@
   #include <signal.h>
   #define cPathsep '/'
 
-  #include <malloc.h>     // malloc
   #include <stdlib.h>     // atoi
   #include <errno.h>
   #define WOULDBLOCK EWOULDBLOCK
@@ -149,7 +148,6 @@
 #include <ctype.h>
 #include <fcntl.h>
 #include <assert.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <time.h>
 #include <stdarg.h>     // vsnprintf
