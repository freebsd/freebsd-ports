--- generic/itcl_class.c.orig	Thu Oct 23 17:58:16 2003
+++ generic/itcl_class.c	Thu Oct 23 17:59:01 2003
@@ -960,7 +960,7 @@
      *    it--as it is being resolved again by the compiler.
      */
     cmdPtr = (Command*)mfunc->accessCmd;
-    if (!cmdPtr || cmdPtr->deleted) {
+    if (!cmdPtr || (cmdPtr->flags & CMD_IS_DELETED)) {
         mfunc->accessCmd = NULL;
 
         if ((flags & TCL_LEAVE_ERR_MSG) != 0) {
