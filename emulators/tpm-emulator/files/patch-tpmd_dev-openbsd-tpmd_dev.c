--- tpmd_dev/openbsd/tpmd_dev.c.orig	2010-07-06 06:21:20.000000000 +0900
+++ tpmd_dev/openbsd/tpmd_dev.c	2010-10-25 02:56:43.630557372 +0900
@@ -32,7 +32,7 @@
 #include <sys/proc.h>
 #include <machine/intr.h>
 
-#include "tpm_dev.h"
+#include "tpmd_dev.h"
 
 
 int	tpmopen __P((dev_t dev, int oflags, int devtype, struct proc *p));
@@ -57,7 +57,7 @@
 cdev_decl(tpm);
 
 /* define our cdev struct containing the functions */
-static struct cdevsw cdev_tpm = cdev_tpm_init(1,tpm);
+static struct cdevsw cdev_tpm = cdev_tpmd_init(1,tpm);
 
 /* fill in the lkm_dev structure */
 MOD_DEV("tpm",LM_DT_CHAR,-1,&cdev_tpm);
@@ -213,7 +213,7 @@
  	 * sometime returns EINTR
 	 */
 	tpmd_sock->so_rcv.sb_flags |= SB_NOINTR;
-	error = soreceive(tpmd_sock,NULL,uio,NULL,NULL,NULL);
+	error = soreceive(tpmd_sock,NULL,uio,NULL,NULL,NULL,0);
 
 	if (error) {
 		debug("soreceive() failed %i",error);
