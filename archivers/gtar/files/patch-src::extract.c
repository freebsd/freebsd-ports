Index: src/extract.c
===================================================================
RCS file: /home/ncvs/src/contrib/tar/src/extract.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -d -u -r1.1.1.1 -r1.3
--- src/extract.c	4 Jun 2002 10:37:44 -0000	1.1.1.1
+++ src/extract.c	7 Jun 2002 06:02:35 -0000	1.3
@@ -19,6 +19,8 @@
    with this program; if not, write to the Free Software Foundation, Inc.,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
+/* $FreeBSD$ */
+
 #include "system.h"
 #include <quotearg.h>
 
@@ -110,7 +112,9 @@
 extr_init (void)
 {
   we_are_root = geteuid () == 0;
+#ifndef __FreeBSD__
   same_permissions_option += we_are_root;
+#endif
   same_owner_option += we_are_root;
   xalloc_fail_func = extract_finish;
 
