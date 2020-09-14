https://bugzilla.mozilla.org/show_bug.cgi?id=1426865

Add "dumb" patch to fix undefined symbols when trying to build gjs against
this spidermonkey version.

This issue was fix in firefox and backported to esr 68.

--- js/public/TypeDecls.h.orig	2020-08-17 18:33:37 UTC
+++ js/public/TypeDecls.h
@@ -20,6 +20,8 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#pragma GCC visibility push(default)
+
 #include "js-config.h"
 #include "jstypes.h"
 
@@ -123,6 +125,8 @@ using HandleVector = Handle<StackGCVector<T>>;
 template <typename T>
 using MutableHandleVector = MutableHandle<StackGCVector<T>>;
 }  // namespace JS
+
+#pragma GCC visibility pop
 
 using jsid = JS::PropertyKey;
 
