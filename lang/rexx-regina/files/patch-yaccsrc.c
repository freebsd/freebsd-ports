--- yaccsrc.c.orig	2021-01-14 22:34:08 UTC
+++ yaccsrc.c
@@ -96,6 +96,8 @@ static char *RCSid = "$Id: yaccsrc.c,v 1.47 2019/04/06
  *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
+
 #include "rexx.h"
 #include <time.h>
 
