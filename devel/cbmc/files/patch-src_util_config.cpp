--- src/util/config.cpp.orig	2026-08-02 21:22:02 UTC
+++ src/util/config.cpp
@@ -1088,6 +1088,16 @@ bool configt::set(const cmdlinet &cmdline)
     ansi_c.char_is_unsigned = false;
     ansi_c.long_double_width = 8 * 8;
   }
+  else if(
+    os == "freebsd" &&
+    (arch == "powerpc" || arch == "ppc64" || arch == "ppc64le"))
+  {
+    // FreeBSD/PowerPC does not use the 128-bit long double assumed by
+    // set_arch_spec_power(): it is 64-bit, except on powerpc64le since
+    // FreeBSD 16.0, where it is IEEE binary128. Follow the toolchain
+    // instead of hard-coding either width.
+    ansi_c.long_double_width = sizeof(long double) * CHAR_BIT;
+  }
 
   // Let's check some of the type widths in case we run
   // the same architecture and OS that we are verifying for.
