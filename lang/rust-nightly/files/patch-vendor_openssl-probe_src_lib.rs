--- vendor/openssl-probe-0.1.6/src/lib.rs
+++ vendor/openssl-probe-0.1.6/src/lib.rs
@@ -26,6 +26,7 @@ pub fn find_certs_dirs() -> Vec<PathBuf> {
 /// found.
 ///
 /// This will only search known system locations.
+#[cfg(not(target_os = "freebsd"))]
 pub fn candidate_cert_dirs() -> impl Iterator<Item = &'static Path> {
     // see http://gagravarr.org/writing/openssl-certs/others.shtml
     [
@@ -52,6 +53,19 @@ pub fn candidate_cert_dirs() -> impl Iterator<Item = &'static Path> {
     .map(Path::new)
     .filter(|p| p.exists())
 }
+#[cfg(target_os = "freebsd")]
+pub fn candidate_cert_dirs() -> impl Iterator<Item = &'static Path> {
+    // see manpage of certctl(8): https://man.freebsd.org/cgi/man.cgi?query=certctl&sektion=8
+    // see security/openssl* ports
+    [
+        "/etc/ssl",
+        "/usr/local/etc/ssl",
+        "/usr/local/openssl",
+    ]
+    .iter()
+    .map(Path::new)
+    .filter(|p| p.exists())
+}
 
 /// Deprecated as this isn't sound, use [`init_openssl_env_vars`] instead.
 #[doc(hidden)]
@@ -169,6 +183,7 @@ pub fn probe() -> ProbeResult {
     for certs_dir in candidate_cert_dirs() {
         // cert.pem looks to be an openssl 1.0.1 thing, while
         // certs/ca-certificates.crt appears to be a 0.9.8 thing
+        #[cfg(not(target_os = "freebsd"))]
         let cert_filenames = [
             "cert.pem",
             "certs.pem",
@@ -181,6 +196,11 @@ pub fn probe() -> ProbeResult {
             "CARootCertificates.pem",
             "tls-ca-bundle.pem",
         ];
+        #[cfg(target_os = "freebsd")]
+        let cert_filenames = [
+            "cert.pem",
+            "ca-root-nss.crt",
+        ];
         if result.cert_file.is_none() {
             result.cert_file = cert_filenames
                 .iter()
