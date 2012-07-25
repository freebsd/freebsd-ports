This patch adds support for VIMAGE to VBoxNetAdp and thus
also fixes that panic.

Submitted by:	Mikolaj Golub <trociny at freebsd.org>
--- src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c.orig	2012-06-20 15:17:03.000000000 +0200
+++ src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c	2012-07-25 18:30:13.695891353 +0200
@@ -68,6 +68,22 @@
 #define VBOXNETADP_OS_SPECFIC 1
 #include "../VBoxNetAdpInternal.h"
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800500
+# include <sys/jail.h>
+# include <net/vnet.h>
+
+# define VBOXCURVNET_SET(arg)           CURVNET_SET_QUIET(arg)
+# define VBOXCURVNET_SET_FROM_UCRED()   VBOXCURVNET_SET(CRED_TO_VNET(curthread->td_ucred))
+# define VBOXCURVNET_RESTORE()          CURVNET_RESTORE()
+
+#else /* !defined(__FreeBSD_version) || __FreeBSD_version < 800500 */
+
+# define VBOXCURVNET_SET(arg)
+# define VBOXCURVNET_SET_FROM_UCRED()
+# define VBOXCURVNET_RESTORE()
+
+#endif /* !defined(__FreeBSD_version) || __FreeBSD_version < 800500 */
+
 static int VBoxNetAdpFreeBSDCtrlioctl(struct cdev *, u_long, caddr_t, int flags,
     struct thread *);
 static struct cdevsw vboxnetadp_cdevsw =
@@ -260,6 +276,7 @@
 {
     struct ifnet *ifp;
 
+    VBOXCURVNET_SET_FROM_UCRED();
     ifp = if_alloc(IFT_ETHER);
     if (ifp == NULL)
         return VERR_NO_MEMORY;
@@ -279,6 +296,7 @@
 
     strncpy(pThis->szName, ifp->if_xname, VBOXNETADP_MAX_NAME_LEN);
     pThis->u.s.ifp = ifp;
+    VBOXCURVNET_RESTORE();
     return 0;
 }
 
@@ -287,6 +305,8 @@
     struct ifnet *ifp;
 
     ifp = pThis->u.s.ifp;
+    VBOXCURVNET_SET(ifp->if_vnet);
     ether_ifdetach(ifp);
     if_free(ifp);
+    VBOXCURVNET_RESTORE();
 }
