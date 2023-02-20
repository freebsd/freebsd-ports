--- io_internal.h.orig	2021-12-03 03:57:20.158865000 +0100
+++ io_internal.h	2021-12-03 03:57:28.438206000 +0100
@@ -83,7 +83,7 @@
 my_extern long first_readable;
 my_extern long first_writeable;
 
-my_extern long first_deferred;
+extern long first_deferred;
 
 my_extern enum __io_waitmode {
   UNDECIDED,
