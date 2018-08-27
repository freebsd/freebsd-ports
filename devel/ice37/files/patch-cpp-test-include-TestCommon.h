--- cpp/test/include/TestCommon.h.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/include/TestCommon.h
@@ -38,6 +38,22 @@
 #   endif
 #endif
 
+#if defined(__FreeBSD__)
+extern "C" { int sysctlbyname(const char *name, void *oldp, size_t *oldlenp,
+                 const void *newp, size_t newlen); }
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
