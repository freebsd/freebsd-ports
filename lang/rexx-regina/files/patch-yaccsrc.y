--- yaccsrc.y.orig	2021-01-14 22:26:31 UTC
+++ yaccsrc.y
@@ -23,6 +23,8 @@ static char *RCSid = "$Id: yaccsrc.y,v 1.44 2019/04/06
  *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
+
 #include "rexx.h"
 #include <time.h>
 
