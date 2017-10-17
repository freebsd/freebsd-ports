--- src/net/common/ircthread.cpp.orig	2014-01-10 21:18:20 UTC
+++ src/net/common/ircthread.cpp
@@ -32,14 +32,15 @@
 #include <net/socket_helper.h>
 #include <net/ircthread.h>
 #include <net/socket_msg.h>
-#include <libircclient/libircclient.h>
+#include <libircclient.h>
+#include <libirc_rfcnumeric.h>
 
 // We need to do the following to handle different versions of libircclient.
 // Sadly, libircclient doesn't have actual definitions for its versions in its headers.
 // However, we can use a definition that appeared in the same version we need
 // to check for. Hacky, but hey, it works.
 #ifdef LIBIRC_OPTION_SSL_NO_VERIFY
-#include <libircclient/libirc_rfcnumeric.h>
+#include <libirc_rfcnumeric.h>
 #endif
 
 #include <boost/algorithm/string/predicate.hpp>
