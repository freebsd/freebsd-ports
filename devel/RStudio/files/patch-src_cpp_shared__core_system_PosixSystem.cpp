--- src/cpp/shared_core/system/PosixSystem.cpp.orig	2021-06-09 01:52:44 UTC
+++ src/cpp/shared_core/system/PosixSystem.cpp
@@ -29,8 +29,10 @@
 #include <memory.h>
 #include <netdb.h>
 #include <pwd.h>
+#include <netinet/in.h> // for sa_family_t
+#include <sys/socket.h> // for struct sockaddr
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #endif
 
@@ -80,7 +82,7 @@ Error restorePrivilegesImpl(uid_t in_uid)
 
 Error enableCoreDumps()
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 1);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
