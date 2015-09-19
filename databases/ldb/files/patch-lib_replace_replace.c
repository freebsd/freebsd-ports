From 035dd6447a06409c2df5ed559218f52479621abd Mon Sep 17 00:00:00 2001
From: Volker Lendecke <vl@samba.org>
Date: Tue, 18 Aug 2015 20:57:27 +0200
Subject: [PATCH] replace: Fix bug 11455

Don't call rep_strtoull recursively

Signed-off-by: Volker Lendecke <vl@samba.org>
Bug: https://bugzilla.samba.org/show_bug.cgi?id=11455

https://lists.samba.org/archive/samba-technical/2015-July/108587.html
https://lists.samba.org/archive/samba-technical/2015-July/108588.html

--- ./lib/replace/replace.c.orig	2015-09-18 23:51:08 UTC
+++ ./lib/replace/replace.c	2015-09-18 23:51:08 UTC
@@ -518,8 +518,10 @@
 }
 #else
 #ifdef HAVE_BSD_STRTOLL
+#undef strtoll
 long long int rep_strtoll(const char *str, char **endptr, int base)
 {
+	int errno0 = errno;
 	long long int nb = strtoll(str, endptr, base);
 	/* With glibc EINVAL is only returned if base is not ok */
 	if (errno == EINVAL) {
@@ -528,7 +530,7 @@
 			 * able to make the convertion.
 			 * Let's reset errno.
 			 */
-			errno = 0;
+			errno = errno0;
 		}
 	}
 	return nb;
@@ -551,26 +553,24 @@
 #endif
 }
 #else
-#ifdef HAVE_BSD_STRTOLL
-#ifdef HAVE_STRTOUQ
+#ifdef HAVE_BSD_STRTOLL /* yes, it's not HAVE_BSD_STRTOULL */
+#undef strtoull
 unsigned long long int rep_strtoull(const char *str, char **endptr, int base)
 {
-	unsigned long long int nb = strtouq(str, endptr, base);
-	/* In linux EINVAL is only returned if base is not ok */
+	int errno0 = errno;
+	unsigned long long int nb = strtoull(str, endptr, base);
+	/* With glibc EINVAL is only returned if base is not ok */
 	if (errno == EINVAL) {
 		if (base == 0 || (base >1 && base <37)) {
 			/* Base was ok so it's because we were not
 			 * able to make the convertion.
 			 * Let's reset errno.
 			 */
-			errno = 0;
+			errno = errno0;
 		}
 	}
 	return nb;
 }
-#else
-#error "You need the strtouq function"
-#endif /* HAVE_STRTOUQ */
 #endif /* HAVE_BSD_STRTOLL */
 #endif /* HAVE_STRTOULL */
 
