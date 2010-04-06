--- src/userinfo.c.orig	2010-04-06 09:21:49.000000000 -0300
+++ src/userinfo.c	2010-04-06 09:22:18.000000000 -0300
@@ -5,6 +5,9 @@
  * You may distribute this file under the terms the GNU General Public
  * License.  See the file COPYING for more information.
  */
+
+#define JED_HOSTNAME "%%JED_HOSTNAME%%"
+
 #include "config.h"
 #include "jed-feat.h"
 
