--- galerautils/src/gu_asio.hpp.orig	2017-01-25 07:55:06 UTC
+++ galerautils/src/gu_asio.hpp
@@ -32,6 +32,19 @@
 #endif // __GNUG__
 #endif // ! HAVE_SYSTEM_ASIO
 
+#ifdef ASIO_HPP
+#error asio.hpp is already included before gu_asio.hpp, can't customize asio.hpp
+#endif // ASIO_HPP
+
+#include "asio/version.hpp"
+
+// ASIO does not interact well with kqueue before ASIO 1.10.5, see
+// https://readlist.com/lists/freebsd.org/freebsd-current/23/119264.html
+// http://think-async.com/Asio/asio-1.10.6/doc/asio/history.html#asio.history.asio_1_10_5
+#if ASIO_VERSION < 101005
+# define ASIO_DISABLE_KQUEUE
+#endif // ASIO_VERSION < 101005
+
 #include "asio.hpp"
 #include "asio/ssl.hpp"
 
