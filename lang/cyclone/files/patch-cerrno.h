--- lib/cerrno.h.or	Fri Jan  4 00:15:32 2002
+++ lib/cerrno.h	Fri Jan  4 00:16:28 2002
@@ -31,6 +31,9 @@
 /* x86 linux */
 int @ __errno_location(void);
 #define errno (*Std::__errno_location())
+#elif defined(__FreeBSD__)
+int @ __error(void);
+#define errno (*Std::__error())
 #else
 /* cygwin, BSD */
 int @ __errno(void);
--- include/cerrno.h.or	Fri Jan  4 00:15:32 2002
+++ include/cerrno.h	Fri Jan  4 00:16:28 2002
@@ -31,6 +31,9 @@
 /* x86 linux */
 int @ __errno_location(void);
 #define errno (*Std::__errno_location())
+#elif defined(__FreeBSD__)
+int @ __error(void);
+#define errno (*Std::__error())
 #else
 /* cygwin, BSD */
 int @ __errno(void);
