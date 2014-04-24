From nox Mon Sep 17 00:00:00 2001
From: Juergen Lock <nox@jelal.kn-bremen.de>
Date: 05 Apr 2014 02:04:00 +0200
Subject: Fix bsd-user FreeBSD fchflags() syscall (typo)

Fix bsd-user FreeBSD fchflags() syscall. (typo)

Signed-off-by: Juergen Lock <nox@jelal.kn-bremen.de>

--- a/bsd-user/syscall.c
+++ b/bsd-user/syscall.c
@@ -627,7 +627,7 @@ abi_long do_freebsd_syscall(void *cpu_en
         break;
 
     case TARGET_FREEBSD_NR_fchflags: /* fchflags(2) */
-        ret = do_bsd_fchflags(arg2, arg2);
+        ret = do_bsd_fchflags(arg1, arg2);
         break;
 
     case TARGET_FREEBSD_NR_chroot: /* chroot(2) */
