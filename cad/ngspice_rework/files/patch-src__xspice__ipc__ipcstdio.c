--- src/xspice/ipc/ipcstdio.c.orig	Mon Nov 19 15:13:29 2007
+++ src/xspice/ipc/ipcstdio.c	Mon Nov 19 15:18:42 2007
@@ -40,7 +40,7 @@
      Ipc_Wait_t         wait;
 {
    printf ("GET_LINE\n");
-   gets (str);
+   fgets (str, sizeof str, stdin);
    *len = strlen (str);
    return IPC_STATUS_OK;
 }
