--- cmake/ConfigureChecks.cmake.orig	2024-01-01 18:36:58 UTC
+++ cmake/ConfigureChecks.cmake
@@ -17,6 +17,7 @@ check_include_file(io.h         HAVE_IO_H)      # inte
 check_include_file(grp.h        HAVE_GRP_H)     # dbus-sysdeps-util-win.c
 check_include_file(inttypes.h     HAVE_INTTYPES_H)   # dbus-pipe.h
 check_include_file(io.h         HAVE_IO_H)      # internal
+check_include_file(linux/close_range.h HAVE_LINUX_CLOSE_RANGE_H)
 check_include_file(locale.h     HAVE_LOCALE_H)
 check_include_file(memory.h     HAVE_MEMORY_H)
 check_include_file(signal.h     HAVE_SIGNAL_H)
@@ -31,6 +32,7 @@ check_include_file(sys/stat.h     HAVE_SYS_STAT_H)
 check_include_file(sys/random.h     HAVE_SYS_RANDOM_H)
 check_include_file(sys/resource.h     HAVE_SYS_RESOURCE_H)
 check_include_file(sys/stat.h     HAVE_SYS_STAT_H)
+check_include_file(sys/syscall.h HAVE_SYS_SYSCALL_H)
 check_include_file(sys/types.h     HAVE_SYS_TYPES_H)
 check_include_file(sys/uio.h     HAVE_SYS_UIO_H)
 check_include_file(sys/prctl.h  HAVE_SYS_PRCTL_H)
