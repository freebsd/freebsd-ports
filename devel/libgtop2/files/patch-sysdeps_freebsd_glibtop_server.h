--- sysdeps/freebsd/glibtop_server.h.orig	Mon Oct 20 11:19:49 2003
+++ sysdeps/freebsd/glibtop_server.h	Mon Aug  8 15:10:14 2005
@@ -21,8 +21,8 @@
    Boston, MA 02111-1307, USA.
 */
 
-#ifndef __GLIBTOP_SERVER_H__
-#define __GLIBTOP_SERVER_H__
+#ifndef __FREEBSD__GLIBTOP_SERVER_H__
+#define __FREEBSD__GLIBTOP_SERVER_H__
 
 G_BEGIN_DECLS
 
@@ -45,6 +45,7 @@ G_BEGIN_DECLS
 #define GLIBTOP_SUID_PROC_ARGS		(1 << GLIBTOP_SYSDEPS_PROC_ARGS)
 #define GLIBTOP_SUID_PROC_MAP		(1 << GLIBTOP_SYSDEPS_PROC_MAP)
 #define GLIBTOP_SUID_NETLOAD		(1 << GLIBTOP_SYSDEPS_NETLOAD)
+#define GLIBTOP_SUID_NETLIST		0
 #define GLIBTOP_SUID_PPP		(1 << GLIBTOP_SYSDEPS_PPP)
 
 G_END_DECLS
