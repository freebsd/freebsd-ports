
$FreeBSD$

--- src/ComTerp/comterp.c.orig
+++ src/ComTerp/comterp.c
@@ -74,6 +74,7 @@
 #if __GNUC__>=3
 #include <fstream.h>
 #endif
+#include <errno.h>
 
 #define TITLE "ComTerp"
 #define STREAM_MECH
@@ -896,7 +897,7 @@
     fbuf.attach(fd);
   } else
     fbuf.attach(fileno(stdout));
-#elif (__GNUC__==3 && __GNUC_MINOR__<1) || __GNUC__>3
+#elif (__GNUC__==3 && __GNUC_MINOR__<1) || __GNUC__>3 || defined(__FreeBSD__)
   fileptr_filebuf fbuf(handler() && handler()->wrfptr() 
 	       ? handler()->wrfptr() : stdout, 
 	       ios_base::out);
