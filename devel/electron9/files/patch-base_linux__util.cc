--- base/linux_util.cc.orig	2020-05-26 07:48:14 UTC
+++ base/linux_util.cc
@@ -78,6 +78,9 @@ class DistroNameGetter {
  public:
   DistroNameGetter() {
     static const char* const kFilesToCheck[] = {"/etc/os-release",
+#if defined(OS_BSD)
+	                                        "/usr/local/etc/os-release",
+#endif
                                                 "/usr/lib/os-release"};
     for (const char* file : kFilesToCheck) {
       if (ReadDistroFromOSReleaseFile(file))
