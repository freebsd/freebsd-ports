Index: qemu/slirp/slirp_config.h
@@ -86,7 +86,7 @@
 #undef BAD_SPRINTF
 
 /* Define if you have readv */
-#undef HAVE_READV
+#define HAVE_READV
 
 /* Define if iovec needs to be declared */
 #undef DECLARE_IOVEC
@@ -95,7 +95,7 @@
 #undef DECLARE_SPRINTF
 
 /* Define if you have a POSIX.1 sys/wait.h */
-#undef HAVE_SYS_WAIT_H
+#define HAVE_SYS_WAIT_H
 
 /* Define if you have sys/select.h */
 #define HAVE_SYS_SELECT_H
@@ -107,7 +107,7 @@
 #define HAVE_ARPA_INET_H
 
 /* Define if you have sys/signal.h */
-#undef HAVE_SYS_SIGNAL_H
+#define HAVE_SYS_SIGNAL_H
 
 /* Define if you have sys/stropts.h */
 #undef HAVE_SYS_STROPTS_H
@@ -180,7 +180,7 @@
 #undef HAVE_GRANTPT
 
 /* Define if you have fchmod */
-#undef HAVE_FCHMOD
+#define HAVE_FCHMOD
 
 /* Define if you have <sys/type32.h> */
 #undef HAVE_SYS_TYPES32_H
