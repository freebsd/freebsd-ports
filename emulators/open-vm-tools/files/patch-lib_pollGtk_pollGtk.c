--- lib/pollGtk/pollGtk.c.orig	2021-08-03 01:31:55 UTC
+++ lib/pollGtk/pollGtk.c
@@ -1485,7 +1485,7 @@ Poll_InitGtk(void)
       PollLockingAlwaysEnabled,
    };
 
-   if (g_once_init_enter(&inited)) {
+   if (g_once_init_enter((gsize *)&inited)) {
       gsize didInit = 1;
       Poll_InitWithImpl(&gtkImpl);
       g_once_init_leave(&inited, didInit);
