--- ucb/source/ucp/gvfs/gvfs_content.hxx.ORIG	2011-11-07 16:59:40.000000000 +0000
+++ ucb/source/ucp/gvfs/gvfs_content.hxx	2013-03-09 13:53:52.000000000 +0000
@@ -30,7 +30,8 @@
 #include <com/sun/star/ucb/XContentCreator.hpp>
 #include <ucbhelper/contenthelper.hxx>
 
-#include <glib/gthread.h>
+#include <glib.h>
+//#include <glib/gthread.h>
 #include <libgnomevfs/gnome-vfs-ops.h>
 #include <libgnomevfs/gnome-vfs-directory.h>
 
