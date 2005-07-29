--- desktop/source/pkgchk/pkgchk_packages.cxx.orig	Sun Jan 19 20:00:08 2003
+++ desktop/source/pkgchk/pkgchk_packages.cxx	Sun Jan 19 20:01:51 2003
@@ -124,6 +124,10 @@
 static char const s_platform_path [] = "/macosx_powerpc.plt";
 #elif defined (NETBSD) && defined (SPARC)
 static char const s_platform_path [] = "/netbsd_sparc.plt";
+#elif defined (FREEBSD) && defined (INTEL)
+static char const s_platform_path [] = "/freebsd_x86.plt";
+#elif defined (FREEBSD) && defined (SPARC)
+static char const s_platform_path [] = "/freebsd_sparc.plt";
 #else
 #error "unkonwn platform"
 insert your platform identifier above; inserted for the case the preprocessor ignores error
