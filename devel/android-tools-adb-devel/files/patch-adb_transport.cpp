[----------] 9 tests from transport
[ RUN      ] transport.kick_transport
transport_test.cpp:97: Failure
Value of: t.fd
  Actual: -1
Expected: 42
[  FAILED  ] transport.kick_transport (42 ms)
[ RUN      ] transport.kick_transport_already_kicked
[       OK ] transport.kick_transport_already_kicked (1 ms)

--- adb/transport.cpp.orig	2016-04-16 01:50:54 UTC
+++ adb/transport.cpp
@@ -307,9 +307,13 @@ void kick_transport(atransport* t) {
     adb_mutex_lock(&transport_lock);
     // As kick_transport() can be called from threads without guarantee that t is valid,
     // check if the transport is in transport_list first.
+#ifdef __GLIBC__
     if (std::find(transport_list.begin(), transport_list.end(), t) != transport_list.end()) {
+#endif
         kick_transport_locked(t);
+#ifdef __GLIBC__
     }
+#endif
     adb_mutex_unlock(&transport_lock);
 }
 
