--- src/input/Error.hxx.orig	2018-07-06 17:17:27 UTC
+++ src/input/Error.hxx
@@ -30,7 +30,6 @@
  * exist?  This function attempts to recognize exceptions thrown by
  * various input plugins.
  */
-gcc_pure
 bool
 IsFileNotFound(std::exception_ptr e);
 
