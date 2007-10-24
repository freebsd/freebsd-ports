--- libgnomevfs/gnome-vfs-filesystem-type.c.orig	2007-09-17 14:48:45.000000000 -0400
+++ libgnomevfs/gnome-vfs-filesystem-type.c	2007-09-17 14:50:06.000000000 -0400
@@ -65,6 +65,8 @@ static struct FSInfo fs_data[] = {
 	{ "msdosfs"  , N_("MSDOS Volume"), 0 },
 	{ "nfs"      , N_("NFS Network Volume"), 1 },
 	{ "ntfs"     , N_("Windows NT Volume"), 0 },
+	{ "nullfs"   , N_("BSD Loopback Volume"), 1 },
+	{ "zfs"      , N_("ZFS Volume"), 1 },
 	{ "nwfs"     , N_("Netware Volume"), 0 },
 	{ "proc"     , N_("System Volume"), 0 },
 	{ "procfs"   , N_("System Volume"), 0 },
