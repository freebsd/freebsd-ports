diff -ruN acconfig.h acconfig.h
--- acconfig.h	Mon Apr 29 02:26:53 2002
+++ acconfig.h	Sat Jun  8 16:31:07 2002
@@ -47,6 +47,8 @@
 **  Otherwise, we'll use MNTTYPE_NFS.  */
 #undef HAVE_FSID_NFS2
 
+#undef HAVE_MNTENT_H
+
 /* Define if we have MNTTYPE_NFS2 */
 #define HAVE_MNTTYPE_NFS2 0
 
