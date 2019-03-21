--- ../common/exf.c.orig	2007-11-18 16:41:42 UTC
+++ ../common/exf.c
@@ -392,7 +392,7 @@ postinit:
 	 * an error.
 	 */
 	if (rcv_name == NULL && ep->refcnt == 0) {
-		if ((ep->fd = open(oname, O_RDWR)) == -1)
+		if ((ep->fd = open(oname, O_RDONLY)) == -1)
 		    goto no_lock;
 
 		switch (file_lock(sp, oname, &ep->fcntl_fd, ep->fd, 1)) {
