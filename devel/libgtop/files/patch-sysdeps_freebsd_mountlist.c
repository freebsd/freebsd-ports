--- sysdeps/freebsd/mountlist.c.orig	2008-02-15 02:11:59.000000000 -0500
+++ sysdeps/freebsd/mountlist.c	2008-02-15 02:28:14.000000000 -0500
@@ -0,0 +1,168 @@
+/* mountlist.c -- return a list of mounted filesystems
+   Copyright (C) 1991, 1992 Free Software Foundation, Inc.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
+#include <config.h>
+
+#include <glib.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/mount.h>
+
+#include <string.h>
+
+#include <glibtop.h>
+#include <glibtop/mountlist.h>
+
+/* A mount table entry. */
+struct mount_entry
+{
+  char *me_devname;             /* Device node pathname, including "/dev/". */
+  char *me_mountdir;            /* Mount point directory pathname. */
+  char *me_type;                /* "nfs", "4.2", etc. */
+  dev_t me_dev;                 /* Device number of me_mountdir. */
+  struct mount_entry *me_next;
+};
+
+static struct mount_entry *read_filesystem_list (void);
+
+/* Return a list of the currently mounted filesystems, or NULL on error.
+   Add each entry to the tail of the list so that they stay in order.
+*/
+
+static struct mount_entry *
+read_filesystem_list (void)
+{
+  struct mount_entry *mount_list;
+  struct mount_entry *me;
+  struct mount_entry *mtail;
+
+  /* Start the list off with a dummy entry. */
+  me = g_new (struct mount_entry, 1);
+  me->me_next = NULL;
+  mount_list = mtail = me;
+  {
+    struct statfs *fsp;
+    int entries;
+
+    entries = getmntinfo (&fsp, MNT_NOWAIT);
+    if (entries < 0)
+      return NULL;
+    while (entries-- > 0)
+      {
+	me = (struct mount_entry *) g_malloc (sizeof (struct mount_entry));
+	me->me_devname = g_strdup (fsp->f_mntfromname);
+	me->me_mountdir = g_strdup (fsp->f_mntonname);
+	me->me_type = g_strdup (fsp->f_fstypename);
+	me->me_dev = (dev_t) -1;	/* Magic; means not known yet. */
+	me->me_next = NULL;
+
+	/* Add to the linked list. */
+	mtail->me_next = me;
+	mtail = me;
+	fsp++;
+      }
+  }
+
+  /* Free the dummy head. */
+  me = mount_list;
+  mount_list = mount_list->me_next;
+  g_free (me);
+  return mount_list;
+}
+
+static gboolean ignore_mount_entry(const struct mount_entry *me)
+{
+	/* keep sorted */
+	static const char ignored[][17] = {
+		"autofs",
+		"devfs",
+		"fusectl",
+		"linprocfs",
+		"linsysfs",
+		"mfs",
+		"none",
+		"nfs",
+		"nullfs",
+		"nwfs",
+		"portalfs",
+		"proc",
+		"procfs",
+		"smbfs",
+		"tmpfs",
+		"unionfs",
+		"unknown"
+	};
+
+	typedef int (*Comparator)(const void*, const void*);
+
+	return bsearch(me->me_type,
+		       ignored, G_N_ELEMENTS(ignored), sizeof ignored[0],
+		       (Comparator) strcmp) != NULL;
+}
+
+
+glibtop_mountentry *
+glibtop_get_mountlist_s (glibtop *server, glibtop_mountlist *buf, int all_fs)
+{
+	struct mount_entry *entries, *cur, *next;
+
+	GArray *mount_array = g_array_new(FALSE, FALSE,
+					  sizeof(glibtop_mountentry));
+
+	glibtop_init_r (&server, 0, 0);
+
+	memset (buf, 0, sizeof (glibtop_mountlist));
+
+	/* Read filesystem list. */
+
+	if((entries = read_filesystem_list ()) == NULL)
+		return NULL;
+
+	for (cur = &entries[0]; cur != NULL; cur = next) {
+
+		if(all_fs || !ignore_mount_entry(cur)) {
+			/* add a new glibtop_mountentry */
+			glibtop_mountentry e;
+
+			g_strlcpy(e.devname,  cur->me_devname,  sizeof e.devname);
+			g_strlcpy(e.mountdir, cur->me_mountdir, sizeof e.mountdir);
+			g_strlcpy(e.type,     cur->me_type,     sizeof e.type);
+			e.dev = cur->me_dev;
+
+			g_array_append_val(mount_array, e);
+		}
+
+		/* free current mount_entry and move to the next */
+		next = cur->me_next;
+		g_free(cur->me_devname);
+		g_free(cur->me_mountdir);
+		g_free(cur->me_type);
+		g_free(cur);
+	}
+
+	buf->size   = sizeof (glibtop_mountentry);
+	buf->number = mount_array->len;
+	buf->total  = buf->number * buf->size;
+
+	buf->flags  = (1 << GLIBTOP_MOUNTLIST_SIZE)
+	  | (1 << GLIBTOP_MOUNTLIST_NUMBER)
+	  | (1 << GLIBTOP_MOUNTLIST_TOTAL);
+
+	return (glibtop_mountentry*) g_array_free(mount_array, FALSE);
+}
