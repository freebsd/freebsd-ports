--- src/VBox/Runtime/r3/freebsd/fileaio-freebsd.cpp.orig	2013-11-29 14:24:23.000000000 -0500
+++ src/VBox/Runtime/r3/freebsd/fileaio-freebsd.cpp	2013-12-13 17:32:50.000000000 -0500
@@ -124,7 +124,7 @@
                          &cReqsOutstandingMax,       /* Where to store the old value. */
                          &cbParameter,               /* Size of the memory pointed to. */
                          NULL,                       /* Where the new value is located. */
-                         NULL);                      /* Where the size of the new value is stored. */
+                         0);                         /* Where the size of the new value is stored. */
     if (rcBSD == -1)
     {
         /* ENOENT means the value is unknown thus the module is not loaded. */
