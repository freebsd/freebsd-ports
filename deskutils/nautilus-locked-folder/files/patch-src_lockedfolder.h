--- src/lockedfolder.h.orig	2009-01-11 13:41:26.000000000 -0500
+++ src/lockedfolder.h	2009-01-11 13:41:33.000000000 -0500
@@ -20,6 +20,7 @@ Boston, MA 02111-1307, USA. */
 #define LF_ENCRYPT 1
 #define LF_DECRYPT 0
 
+#include <sys/types.h>
 #include <glade/glade.h>
 
 
