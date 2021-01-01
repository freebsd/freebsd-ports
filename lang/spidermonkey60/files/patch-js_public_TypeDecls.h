https://bugzilla.mozilla.org/show_bug.cgi?id=1426865

Add "dumb" patch to fix undefined symbols when trying to build gjs against
this spidermonkey version.

This issue was fix in firefox and backported to esr 68.

--- js/public/TypeDecls.h.orig	2019-09-01 13:09:17 UTC
+++ js/public/TypeDecls.h
@@ -20,6 +20,8 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#pragma GCC visibility push(default)
+
 #include "js-config.h"
 
 typedef uint8_t jsbytecode;
@@ -89,5 +91,7 @@ typedef PersistentRooted<JS::Symbol*> PersistentRooted
 typedef PersistentRooted<Value> PersistentRootedValue;
 
 }  // namespace JS
+
+#pragma GCC visibility pop
 
 #endif /* js_TypeDecls_h */
