--- src/interfaces/libpq/fe-auth.c.orig	Mon Aug  1 11:19:56 2005
+++ src/interfaces/libpq/fe-auth.c	Mon Aug  1 11:21:00 2005
@@ -454,14 +454,13 @@
 	struct iovec iov;
 	struct msghdr msg;
 
-#ifdef HAVE_STRUCT_CMSGCRED
+#if defined(HAVE_STRUCT_CMSGCRED)
 	/* Prevent padding */
 	char		cmsgmem[sizeof(struct cmsghdr) + sizeof(struct cmsgcred)];
 
 	/* Point to start of first structure */
 	struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
-#endif
-#ifdef HAVE_STRUCT_SOCKCRED
+#elif defined(HAVE_STRUCT_SOCKCRED)
 	/* Prevent padding */
 	char		cmsgmem[sizeof(struct cmsghdr) + sizeof(struct sockcred)];
 
