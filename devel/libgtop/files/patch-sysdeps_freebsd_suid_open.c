--- sysdeps/freebsd/suid_open.c.orig	2009-12-13 13:47:12.739004000 -0500
+++ sysdeps/freebsd/suid_open.c	2009-12-13 18:37:51.000000000 -0500
@@ -0,0 +1,92 @@
+/* Copyright (C) 1998 Joshua Sled
+   This file is part of LibGTop 1.0.
+
+   Contributed by Joshua Sled <jsled@xcf.berkeley.edu>, July 1998.
+
+   LibGTop is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License,
+   or (at your option) any later version.
+
+   LibGTop is distributed in the hope that it will be useful, but WITHOUT
+   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
+   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
+   for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with LibGTop; see the file COPYING. If not, write to the
+   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.
+*/
+
+#include <config.h>
+#include <glibtop.h>
+#include <glibtop/error.h>
+#include <glibtop/cpu.h>
+#include <glibtop/open.h>
+#include <glibtop/init_hooks.h>
+
+
+/* !!! THIS FUNCTION RUNS SUID ROOT - CHANGE WITH CAUTION !!! */
+
+void
+glibtop_init_p (glibtop *server, const unsigned long features,
+		const unsigned flags)
+{
+	const _glibtop_init_func_t *init_fkt;
+
+	if (server == NULL)
+		glibtop_error_r (NULL, "glibtop_init_p (server == NULL)");
+
+	/* Do the initialization, but only if not already initialized. */
+
+	if ((server->flags & _GLIBTOP_INIT_STATE_SYSDEPS) == 0) {
+		glibtop_open_p (server, "glibtop", features, flags);
+
+		for (init_fkt = _glibtop_init_hook_p; *init_fkt; init_fkt++)
+			(*init_fkt) (server);
+
+		server->flags |= _GLIBTOP_INIT_STATE_SYSDEPS;
+	}
+}
+
+void
+glibtop_open_p (glibtop *server, const char *program_name,
+		const unsigned long features,
+		const unsigned flags)
+{
+	char errbuf[_POSIX2_LINE_MAX];
+#ifdef DEBUG
+	fprintf (stderr, "DEBUG (%d): glibtop_open_p ()\n", getpid ());
+#endif
+
+	/* !!! WE ARE ROOT HERE - CHANGE WITH CAUTION !!! */
+	server->machine.uid = getuid ();
+	server->machine.euid = geteuid ();
+	server->machine.gid = getgid ();
+	server->machine.egid = getegid ();
+	/* Setup machine-specific data */
+	server->machine.kd = kvm_openfiles (NULL, NULL, NULL, O_RDONLY, errbuf);
+
+	if (server->machine.kd == NULL)
+		glibtop_error_io_r (server, "kvm_open");
+
+	/* Drop priviledges. */
+
+	if (setreuid (server->machine.euid, server->machine.uid))
+		_exit (1);
+
+	if (setregid (server->machine.egid, server->machine.gid))
+		_exit (1);
+
+	/* !!! END OF SUID ROOT PART !!! */
+
+	/* Our effective uid is now those of the user invoking the server,
+	 * so we do no longer have any priviledges. */
+
+	/* NOTE: On FreeBSD, we do not need to be suid root, we just need to
+	 * be sgid kmem.
+	 *
+	 * The server will only use setegid() to get back it's priviledges,
+	 * so it will fail if it is suid root and not sgid kmem. */
+}
