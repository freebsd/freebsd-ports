
$FreeBSD$

--- src/extract.c.orig	Mon Sep 24 20:55:17 2001
+++ src/extract.c	Wed Oct  2 19:10:55 2002
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
 
@@ -1019,10 +1023,19 @@
       {
 	struct stat st1, st2;
 	int e;
+	size_t skiplinkcrud;
+
+	if (absolute_names_option)
+	  skiplinkcrud = 0;
+	else {
+	  skiplinkcrud = FILESYSTEM_PREFIX_LEN (current_link_name);
+	  while (ISSLASH (current_link_name[skiplinkcrud]))
+	    skiplinkcrud++;
+	}
 
 	/* MSDOS does not implement links.  However, djgpp's link() actually
 	   copies the file.  */
-	status = link (current_link_name, CURRENT_FILE_NAME);
+	status = link (current_link_name + skiplinkcrud, CURRENT_FILE_NAME);
 
 	if (status == 0)
 	  {
