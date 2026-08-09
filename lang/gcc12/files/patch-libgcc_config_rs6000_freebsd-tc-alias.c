--- /dev/null
+++ libgcc/config/rs6000/freebsd-tc-alias.c
@@ -0,0 +1,29 @@
+/* clang emits __multc3/__divtc3 (TCmode) for complex IEEE-128 long double,
+   where gcc uses the KCmode names __mulkc3/__divkc3.  Provide TCmode forwarders
+   so clang-built shared libraries that link gcc's libgcc_s (e.g. USES=fortran
+   ports mixing a clang C compile with gfortran) resolve them.  These are real
+   symbols, so mkmap-symver keeps them in the exported version map -- unlike a
+   link-time --defsym alias.  The __asm__ names are not rewritten: the rs6000
+   IEEE-128 name mangling is disabled on FreeBSD, and only libgcc2.c's own
+   mode-based naming turns its __multc3/__divtc3 into __mulkc3/__divkc3.  */
+
+extern _Complex long double __mulkc3 (_Complex long double, _Complex long double);
+extern _Complex long double __divkc3 (_Complex long double, _Complex long double);
+
+__attribute__ ((visibility ("default")))
+_Complex long double __freebsd_multc3 (_Complex long double, _Complex long double) __asm__ ("__multc3");
+
+_Complex long double
+__freebsd_multc3 (_Complex long double a, _Complex long double b)
+{
+  return __mulkc3 (a, b);
+}
+
+__attribute__ ((visibility ("default")))
+_Complex long double __freebsd_divtc3 (_Complex long double, _Complex long double) __asm__ ("__divtc3");
+
+_Complex long double
+__freebsd_divtc3 (_Complex long double a, _Complex long double b)
+{
+  return __divkc3 (a, b);
+}
