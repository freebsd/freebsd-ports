--- cpp/test/include/TestHelper.h.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/include/TestHelper.h
@@ -199,4 +199,20 @@ runTest(int argc, char* argv[])
 
 #define test(ex) ((ex) ? ((void)0) : ::Test::testFailed(#ex, __FILE__, __LINE__))
 
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
 #endif
