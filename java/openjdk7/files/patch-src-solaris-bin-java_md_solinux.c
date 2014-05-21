--- jdk/src/solaris/bin/java_md_solinux.c
+++ jdk/src/solaris/bin/java_md_solinux.c
@@ -899,8 +899,9 @@
  * onwards the filename returned in DL_info structure from dladdr is
  * an absolute pathname so technically realpath isn't required.
  * On Linux we read the executable name from /proc/self/exe.
- * As a fallback, and for platforms other than Solaris and Linux,
- * we use FindExecName to compute the executable name.
+ * On FreeBSD we read the executable name from /proc/curproc/file.
+ * As a fallback, and for platforms other than Solaris, Linux, and
+ * FreeBSD, we use FindExecName to compute the executable name.
  */
 const char*
 SetExecname(char **argv)
@@ -927,9 +928,13 @@
             }
         }
     }
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     {
+#if defined(__FreeBSD__)
+        const char* self = "/proc/curproc/file";
+#else
         const char* self = "/proc/self/exe";
+#endif
         char buf[PATH_MAX+1];
         int len = readlink(self, buf, PATH_MAX);
         if (len >= 0) {
@@ -937,7 +942,7 @@
             exec_path = JLI_StringDup(buf);
         }
     }
-#else /* !__solaris__ && !__linux__ */
+#else /* !__solaris__ && !__linux__ && !__FreeBSD__ */
     {
         /* Not implemented */
     }
