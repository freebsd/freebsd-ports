--- cpp/test/include/TestCommon.h.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/include/TestCommon.h
@@ -18,6 +18,22 @@
 #   include <Ice/LocalException.h>
 #endif
 
+#if defined(__FreeBSD__)
+#  include <sys/types.h>
+#  include <sys/sysctl.h>
+inline bool inFreeBSDJail()
+{
+    int jailed;
+    size_t size = sizeof(jailed);
+    return (sysctlbyname("security.jail.jailed", &jailed, &size, NULL, 0) != -1 || jailed);
+}
+#else
+inline bool inFreeBSDJail()
+{
+    return false;
+}
+#endif
+
 void
 inline print(const std::string& msg)
 {
