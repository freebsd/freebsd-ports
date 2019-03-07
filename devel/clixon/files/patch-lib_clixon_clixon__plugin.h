--- lib/clixon/clixon_plugin.h.orig	2019-02-21 19:04:04 UTC
+++ lib/clixon/clixon_plugin.h
@@ -49,8 +49,6 @@
 /*
  * Types
  */
-/* Dynamicically loadable plugin object handle. @see return value of dlopen(3) */
-typedef void *plghndl_t;
 
 /*! Registered RPC callback function 
  * @param[in]  h       Clicon handle 
