--- sysdeps/freebsd/open.c.orig	2008-05-23 18:13:23.000000000 -0400
+++ sysdeps/freebsd/open.c	2008-09-29 17:23:22.000000000 -0400
@@ -20,76 +20,33 @@
 */
 
 #include <config.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #include <glibtop.h>
-#include <glibtop/error.h>
 #include <glibtop/open.h>
-#include <glibtop/init_hooks.h>
-
-/* !!! THIS FUNCTION RUNS SUID ROOT - CHANGE WITH CAUTION !!! */
-
-void
-glibtop_init_p (glibtop *server, const unsigned long features,
-		const unsigned flags)
-{
-	const _glibtop_init_func_t *init_fkt;
-
-	if (server == NULL)
-		glibtop_error_r (NULL, "glibtop_init_p (server == NULL)");
-
-	/* Do the initialization, but only if not already initialized. */
-
-	if ((server->flags & _GLIBTOP_INIT_STATE_SYSDEPS) == 0) {
-		glibtop_open_p (server, "glibtop", features, flags);
+#include <glibtop/cpu.h>
+#include <glibtop/error.h>
 
-		for (init_fkt = _glibtop_init_hook_p; *init_fkt; init_fkt++)
-			(*init_fkt) (server);
+#include <glibtop_private.h>
 
-		server->flags |= _GLIBTOP_INIT_STATE_SYSDEPS;
-	}
-}
 
 void
-glibtop_open_p (glibtop *server, const char *program_name,
+glibtop_open_s (glibtop *server, const char *program_name,
 		const unsigned long features,
 		const unsigned flags)
 {
-#ifdef DEBUG
-	fprintf (stderr, "DEBUG (%d): glibtop_open_p ()\n", getpid ());
-#endif
+	int ncpus;
+	size_t len;
 
-	/* !!! WE ARE ROOT HERE - CHANGE WITH CAUTION !!! */
+	len = sizeof (ncpus);
+	sysctlbyname ("hw.ncpu", &ncpus, &len, NULL, 0);
+	server->real_ncpu = ncpus - 1;
+	server->ncpu = MIN(GLIBTOP_NCPU - 1, server->real_ncpu);
 
-	server->machine.uid = getuid ();
-	server->machine.euid = geteuid ();
-	server->machine.gid = getgid ();
-	server->machine.egid = getegid ();
 #if defined(__FreeBSD_kernel__)
 	server->os_version_code = __FreeBSD_kernel_version;
 #else
 	server->os_version_code = __FreeBSD_version;
 #endif
-	/* Setup machine-specific data */
-	server->machine.kd = kvm_open (NULL, NULL, NULL, O_RDONLY, "kvm_open");
-
-	if (server->machine.kd == NULL)
-		glibtop_error_io_r (server, "kvm_open");
-
-	/* Drop priviledges. */
-
-	if (setreuid (server->machine.euid, server->machine.uid))
-		_exit (1);
-
-	if (setregid (server->machine.egid, server->machine.gid))
-		_exit (1);
-
-	/* !!! END OF SUID ROOT PART !!! */
-
-	/* Our effective uid is now those of the user invoking the server,
-	 * so we do no longer have any priviledges. */
 
-	/* NOTE: On FreeBSD, we do not need to be suid root, we just need to
-	 * be sgid kmem.
-	 *
-	 * The server will only use setegid() to get back it's priviledges,
-	 * so it will fail if it is suid root and not sgid kmem. */
 }
