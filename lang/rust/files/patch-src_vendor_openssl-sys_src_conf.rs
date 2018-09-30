--- src/vendor/openssl-sys/src/conf.rs.orig	2018-09-16 20:29:19 UTC
+++ src/vendor/openssl-sys/src/conf.rs
@@ -0,0 +1,7 @@
+use *;
+
+extern "C" {
+    pub fn NCONF_new(meth: *mut CONF_METHOD) -> *mut CONF;
+    pub fn NCONF_default() -> *mut CONF_METHOD;
+    pub fn NCONF_free(conf: *mut CONF);
+}
