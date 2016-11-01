--- bindings/cpp/tuntap++.cc.orig	2016-10-29 14:49:34 UTC
+++ bindings/cpp/tuntap++.cc
@@ -7,7 +7,7 @@
 namespace tuntap {
 
 tun::tun()
-    : _dev{tuntap_init()}
+    : _dev(tuntap_init())
 {
     tuntap_start(_dev, TUNTAP_MODE_TUNNEL, TUNTAP_ID_ANY);
 }
@@ -84,7 +84,7 @@ tun::nonblocking(bool b)
 }
 
 tap::tap()
-    : _dev{tuntap_init()}
+    : _dev(tuntap_init())
 {
     tuntap_start(_dev, TUNTAP_MODE_ETHERNET, TUNTAP_ID_ANY);
 }
