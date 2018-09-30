--- src/vendor/openssl/src/ssl/callbacks.rs.orig	2018-09-11 04:49:47 UTC
+++ src/vendor/openssl/src/ssl/callbacks.rs
@@ -381,10 +381,13 @@ pub unsafe extern "C" fn raw_remove_session<F>(
     callback(ctx, session)
 }
 
-#[cfg(ossl110)]
-type DataPtr = *const c_uchar;
-#[cfg(not(ossl110))]
-type DataPtr = *mut c_uchar;
+cfg_if! {
+    if #[cfg(any(ossl110, libressl280))] {
+        type DataPtr = *const c_uchar;
+    } else {
+        type DataPtr = *mut c_uchar;
+    }
+}
 
 pub unsafe extern "C" fn raw_get_session<F>(
     ssl: *mut ffi::SSL,
@@ -505,11 +508,13 @@ where
     }
 }
 
-#[cfg(ossl110)]
-type CookiePtr = *const c_uchar;
-
-#[cfg(not(ossl110))]
-type CookiePtr = *mut c_uchar;
+cfg_if! {
+    if #[cfg(any(ossl110, libressl280))] {
+        type CookiePtr = *const c_uchar;
+    } else {
+        type CookiePtr = *mut c_uchar;
+    }
+}
 
 pub extern "C" fn raw_cookie_verify<F>(
     ssl: *mut ffi::SSL,
