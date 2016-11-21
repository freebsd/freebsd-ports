FreeBSD 9 does not have SOCK_CLOEXEC. Define it to 0, as the code already deals
with it.
Xapian 1.4 has a safesyssocket.h that takes care of this.
--- backends/flint_lock.cc.orig	2016-09-16 01:59:15 UTC
+++ backends/flint_lock.cc
@@ -59,6 +59,10 @@ using namespace std;
 # endif
 #endif
 
+#ifndef SOCK_CLOEXEC
+#define SOCK_CLOEXEC 0
+#endif
+
 FlintLock::reason
 FlintLock::lock(bool exclusive, string & explanation) {
     // Currently we only support exclusive locks.
