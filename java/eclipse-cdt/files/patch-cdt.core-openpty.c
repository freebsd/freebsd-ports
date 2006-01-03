--- eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_3.0.1/src/org.eclipse.cdt.core.freebsd_3.0.1/library/openpty.c.orig	Sat Dec  3 01:10:16 2005
+++ eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_3.0.1/src/org.eclipse.cdt.core.freebsd_3.0.1/library/openpty.c	Sat Dec  3 01:13:46 2005
@@ -20,7 +20,6 @@
 #include <grp.h>
 
 #include <stdlib.h>
-#include <stropts.h>
 
 /**
  * This is taken from R. W. Stevens book.
