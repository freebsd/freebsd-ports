--- src/net/common/ircthread.cpp.orig	2012-02-11 17:57:34.000000000 +0100
+++ src/net/common/ircthread.cpp	2012-03-07 11:03:40.501681051 +0100
@@ -19,7 +19,8 @@
 #include <net/socket_helper.h>
 #include <net/ircthread.h>
 #include <net/socket_msg.h>
-#include <libircclient/libircclient.h>
+#include <libircclient.h>
+#include <libirc_rfcnumeric.h>
 #include <boost/algorithm/string/predicate.hpp>
 #include <queue>
 #include <sstream>
