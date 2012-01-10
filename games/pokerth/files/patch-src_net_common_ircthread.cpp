--- src/net/common/ircthread.cpp.orig	2012-01-04 14:33:45.259685354 +0100
+++ src/net/common/ircthread.cpp	2012-01-04 14:32:53.601974192 +0100
@@ -19,7 +19,7 @@
 #include <net/socket_helper.h>
 #include <net/ircthread.h>
 #include <net/socket_msg.h>
-#include <libircclient/libircclient.h>
+#include <libircclient.h>
 #include <boost/algorithm/string/predicate.hpp>
 #include <queue>
 #include <sstream>
