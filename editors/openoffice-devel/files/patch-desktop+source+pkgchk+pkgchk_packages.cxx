--- ../desktop/source/pkgchk/pkgchk_packages.cxx.orig	Mon Oct 21 13:19:59 2002
+++ ../desktop/source/pkgchk/pkgchk_packages.cxx	Mon Oct 21 13:22:22 2002
@@ -124,6 +124,8 @@
 static char const s_platform_path [] = "/macosx_powerpc.plt";
 #elif defined (NETBSD) && defined (SPARC)
 static char const s_platform_path [] = "/netbsd_sparc.plt";
+#elif defined (FREEBSD) && defined (INTEL)
+static char const s_platform_path [] = "/freebsd_x86.plt";
 #else
 #error "unkonwn platform"
 insert your platform identifier above; inserted for the case the preprocessor ignores error
