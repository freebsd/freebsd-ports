--- include/defs.h.orig	Mon Dec  4 03:44:17 2000
+++ include/defs.h	Mon Dec  4 03:44:17 2000
@@ -0,0 +1,261 @@
+/* include/defs.h.  Generated automatically by configure.  */
+/* include/defs.h.in.  Generated automatically from configure.in by autoheader.  */
+
+/* Define if on AIX 3.
+   System headers sometimes define this.
+   We just want to avoid a redefinition error message.  */
+#ifndef _ALL_SOURCE
+/* #undef _ALL_SOURCE */
+#endif
+
+/* Define if using alloca.c.  */
+/* #undef C_ALLOCA */
+
+/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
+   This function is required for alloca.c support on those systems.  */
+/* #undef CRAY_STACKSEG_END */
+
+/* Define if the `getpgrp' function takes no argument.  */
+#define GETPGRP_VOID 1
+
+/* Define to `int' if <sys/types.h> doesn't define.  */
+/* #undef gid_t */
+
+/* Define if you have alloca, as a function or macro.  */
+#define HAVE_ALLOCA 1
+
+/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
+#define HAVE_ALLOCA_H 1
+
+/* Define to `int' if <sys/types.h> doesn't define.  */
+/* #undef mode_t */
+
+/* Define if your C compiler doesn't accept -c and -o together.  */
+/* #undef NO_MINUS_C_MINUS_O */
+
+/* Define if your Fortran 77 compiler doesn't accept -c and -o together. */
+/* #undef F77_NO_MINUS_C_MINUS_O */
+
+/* Define to `int' if <sys/types.h> doesn't define.  */
+/* #undef pid_t */
+
+/* Define if you need to in order for stat and other things to work.  */
+/* #undef _POSIX_SOURCE */
+
+/* Define as the return type of signal handlers (int or void).  */
+#define RETSIGTYPE void
+
+/* Define to the type of arg1 for select(). */
+/* #undef SELECT_TYPE_ARG1 */
+
+/* Define to the type of args 2, 3 and 4 for select(). */
+/* #undef SELECT_TYPE_ARG234 */
+
+/* Define to the type of arg5 for select(). */
+/* #undef SELECT_TYPE_ARG5 */
+
+/* Define to `unsigned' if <sys/types.h> doesn't define.  */
+/* #undef size_t */
+
+/* If using the C implementation of alloca, define if you know the
+   direction of stack growth for your system; otherwise it will be
+   automatically deduced at run-time.
+ STACK_DIRECTION > 0 => grows toward higher addresses
+ STACK_DIRECTION < 0 => grows toward lower addresses
+ STACK_DIRECTION = 0 => direction of growth unknown
+ */
+/* #undef STACK_DIRECTION */
+
+/* Define if you have the ANSI C header files.  */
+#define STDC_HEADERS 1
+
+/* Define if `sys_siglist' is declared by <signal.h>.  */
+#define SYS_SIGLIST_DECLARED 1
+
+/* Define if you can safely include both <sys/time.h> and <time.h>.  */
+#define TIME_WITH_SYS_TIME 1
+
+/* Define to `int' if <sys/types.h> doesn't define.  */
+/* #undef uid_t */
+
+/* Define this if you have fpathconf(2) */
+#define HAVE_FPATHCONF 1
+
+/* define this if you have getpass(3) */
+#define HAVE_GETPASS 1
+
+/* define this if you have getpgid(2) */
+#define HAVE_GETPGID 1
+
+/* define this if you have gettimeofday(2) */
+#define HAVE_GETTIMEOFDAY 1
+
+/* Define this if you have killpg(2) */
+#define HAVE_KILLPG 1
+
+/* define this if you have memmove(3) */
+#define HAVE_MEMMOVE 1
+
+/* define this if you have scandir(3) */
+#define HAVE_SCANDIR 1
+
+/* define this if you have setenv(3) */
+#define HAVE_SETENV 1
+
+/* define this if you have setsid(2) */
+#define HAVE_SETSID 1
+
+/* define this if you have snprintf(3) */
+#define HAVE_SNPRINTF 1
+
+/* define this if you have strerror(3) */
+#define HAVE_STRERROR 1
+
+/* define if you have strtoul(3) */
+#define HAVE_STRTOUL 1
+
+/* define this if you have sysconf(3) */
+#define HAVE_SYSCONF 1
+
+/* define this if you have uname(2) */
+#define HAVE_UNAME 1
+
+/* define this if you have vsnprintf(3) */
+#define HAVE_VSNPRINTF 1
+
+/* Define this if you have SUN_LEN in <sys/un.h> */
+/* #undef HAVE_SUN_LEN */
+
+/* define this if you don't have struct linger */
+/* #undef NO_STRUCT_LINGER */
+
+/* define if allow sys/time.h with time.h */
+#define TIME_WITH_SYS_TIME 1
+
+/* Define this if your getpgrp is broken posix */
+#define GETPGRP_VOID 1
+
+/* define this if an unsigned long is 32 bits */
+/* #undef UNSIGNED_LONG32 */
+
+/* define this if an unsigned int is 32 bits */
+#define UNSIGNED_INT32 1
+
+/* define this if you are unsure what is is 32 bits */
+/* #undef UNKNOWN_32INT */
+
+/* Define this if you have inet_aton(). */
+#define HAVE_INET_ATON 1
+
+/* Define this if you need to include sys/select.h */
+/* #undef NEED_SYS_SELECT_H */
+
+/*
+ * SOCKS 4 && 5 support.
+ */
+/* #undef SOCKS */
+/* #undef USE_SOCKS */
+/* #undef USE_SOCKS5 */
+/* #undef connect */
+/* #undef getsockname */
+/* #undef bind */
+/* #undef accept */
+/* #undef listen */
+/* #undef select */
+/* #undef dup */
+/* #undef dup2 */
+/* #undef fclose */
+/* #undef gethostbyname */
+/* #undef read */
+/* #undef recv */
+/* #undef recvfrom */
+/* #undef rresvport */
+/* #undef send */
+/* #undef sendto */
+/* #undef shutdown */
+/* #undef write */
+/* #undef Rconnect */
+/* #undef Rgetsockname */
+/* #undef Rgetpeername */
+/* #undef Rbind */
+/* #undef Raccept */
+/* #undef Rlisten */
+/* #undef Rselect */
+
+/* Define this if you have setsid() */
+#define HAVE_SETSID 1
+
+/* Define this if you have tparm(2) */
+#define HAVE_TPARM 1
+
+/* Define this if you have getlogin(3) */
+#define HAVE_GETLOGIN 1
+
+/* Define this if you have terminfo support */
+#define HAVE_TERMINFO 1
+
+/* Define this if you have fchdir() */
+#define HAVE_FCHDIR 1
+
+/* Define this if you have realpath() */
+#define HAVE_REALPATH 1
+
+/* Define this if you have strlcpy() */
+/* #undef HAVE_STRLCPY */
+
+/* Define this if you have strlcat() */
+/* #undef HAVE_STRLCAT */
+
+/* Define this if you have stpcpy() */
+#define HAVE_STPCPY 1
+
+/* The number of bytes in a unsigned int.  */
+#define SIZEOF_UNSIGNED_INT 4
+
+/* The number of bytes in a unsigned long.  */
+/* #undef SIZEOF_UNSIGNED_LONG */
+
+/* Define if you have the <dirent.h> header file.  */
+#define HAVE_DIRENT_H 1
+
+/* Define if you have the <fcntl.h> header file.  */
+#define HAVE_FCNTL_H 1
+
+/* Define if you have the <ndir.h> header file.  */
+/* #undef HAVE_NDIR_H */
+
+/* Define if you have the <netdb.h> header file.  */
+#define HAVE_NETDB_H 1
+
+/* Define if you have the <regex.h> header file.  */
+#define HAVE_REGEX_H 1
+
+/* Define if you have the <sys/dir.h> header file.  */
+/* #undef HAVE_SYS_DIR_H */
+
+/* Define if you have the <sys/fcntl.h> header file.  */
+#define HAVE_SYS_FCNTL_H 1
+
+/* Define if you have the <sys/file.h> header file.  */
+#define HAVE_SYS_FILE_H 1
+
+/* Define if you have the <sys/filio.h> header file.  */
+/* #undef HAVE_SYS_FILIO_H */
+
+/* Define if you have the <sys/ndir.h> header file.  */
+/* #undef HAVE_SYS_NDIR_H */
+
+/* Define if you have the <sys/select.h> header file.  */
+#define HAVE_SYS_SELECT_H 1
+
+/* Define if you have the <sys/syslimits.h> header file.  */
+/* #undef HAVE_SYS_SYSLIMITS_H */
+
+/* Define if you have the <sys/time.h> header file.  */
+#define HAVE_SYS_TIME_H 1
+
+/* Define if you have the <sys/un.h> header file.  */
+#define HAVE_SYS_UN_H 1
+
+/* Define if you have the <termcap.h> header file.  */
+#define HAVE_TERMCAP_H 1
