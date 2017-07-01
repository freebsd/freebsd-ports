From 45d4b59e3f7ef7b41db08f0c11ee5000126cfedb Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Sun, 4 Dec 2016 15:02:54 +0800
Subject: [PATCH] glocalfileoutputstream: Fix symlink writing on FreeBSD and
 NetBSD

FreeBSD, DragonflyBSD and NetBSD support O_NOFOLLOW, but they use error
numbers that are different from what POSIX standard specifies. They are
not going to change the behavior, and existing programs on these systems
already take advantage of this difference. To support them, we have to
add a check in GIO to use different error numbers on these systems.

https://bugzilla.gnome.org/show_bug.cgi?id=775593
---
 gio/glocalfileoutputstream.c | 6 ++++++
 1 file changed, 6 insertions(+)

diff --git a/gio/glocalfileoutputstream.c b/gio/glocalfileoutputstream.c
index 81184a671..4b3733cce 100644
--- gio/glocalfileoutputstream.c
+++ gio/glocalfileoutputstream.c
@@ -763,7 +763,13 @@ handle_overwrite_open (const char    *filename,
 #ifdef O_NOFOLLOW
   is_symlink = FALSE;
   fd = g_open (filename, open_flags | O_NOFOLLOW, mode);
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+  if (fd == -1 && errno == EMLINK)
+#elif defined(__NetBSD__)
+  if (fd == -1 && errno == EFTYPE)
+#else
   if (fd == -1 && errno == ELOOP)
+#endif
     {
       /* Could be a symlink, or it could be a regular ELOOP error,
        * but then the next open will fail too. */
-- 
2.13.0

