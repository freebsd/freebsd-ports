$FreeBSD$

--- jmp.c.orig	Wed Aug 18 00:13:25 2004
+++ jmp.c	Wed Aug 18 00:14:03 2004
@@ -1883,0 +1884 @@
+	int locks;
@@ -1886 +1887 @@
-	int locks = timerstacks_get_need_locks ();
+	locks = timerstacks_get_need_locks ();
