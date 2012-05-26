commit 57abc9df0c354b5780996e356c6815f05a562e0a
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sat May 12 17:20:54 2012 -0300

    Add missing include to fix the build with recent GCCs.
    
    Include <string.h> so that the definitions for memcpy() and friends
    can be found. Fixes the build with GCC 4.6.3, at least.
    
    Reviewed-by:  Andreas Pakulat
    REVIEW:       104926
    (cherry picked from commit f3e0daaba7a9afdd3c01a7a2fd258f523c4f48d0)

diff --git a/util/dbus_socket_transformer/main.cpp b/util/dbus_socket_transformer/main.cpp
index f3734b4..5168e94 100644
--- util/dbus_socket_transformer/main.cpp
+++ util/dbus_socket_transformer/main.cpp
@@ -30,6 +30,7 @@
 #include <assert.h>
 #include <sstream>
 #include <unistd.h>
+#include <string.h>
 
 #ifndef HAVE_MSG_NOSIGNAL
 #define MSG_NOSIGNAL 0
