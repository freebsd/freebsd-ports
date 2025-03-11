--- include/emilua/ambient_authority.hpp.orig	2025-03-05 22:17:52 UTC
+++ include/emilua/ambient_authority.hpp
@@ -10,6 +10,7 @@
 
 #if BOOST_OS_UNIX
 # include <sys/socket.h>
+# include <sys/types.h>
 # include <netdb.h>
 #endif // BOOST_OS_UNIX
 
