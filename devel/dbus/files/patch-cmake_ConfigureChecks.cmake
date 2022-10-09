--- cmake/ConfigureChecks.cmake.orig	2022-09-14 12:12:21 UTC
+++ cmake/ConfigureChecks.cmake
@@ -51,6 +51,7 @@ check_symbol_exists(clearenv     "stdlib.h"         HA
 check_symbol_exists(setenv       "stdlib.h"         HAVE_SETENV)             #  dbus-sysdeps.c
 check_symbol_exists(unsetenv     "stdlib.h"         HAVE_UNSETENV)           #  dbus-sysdeps.c
 check_symbol_exists(clearenv     "stdlib.h"         HAVE_CLEARENV)           #  dbus-sysdeps.c
+check_symbol_exists(closefrom    "unistd.h"         HAVE_CLOSEFROM)          #  dbus-sysdeps-unix.c
 check_symbol_exists(writev       "sys/uio.h"        HAVE_WRITEV)             #  dbus-sysdeps.c, dbus-sysdeps-win.c
 check_symbol_exists(setrlimit    "sys/resource.h"   HAVE_SETRLIMIT)          #  dbus-sysdeps.c, dbus-sysdeps-win.c, test/test-segfault.c
 check_symbol_exists(socketpair   "sys/socket.h"     HAVE_SOCKETPAIR)         #  dbus-sysdeps.c
