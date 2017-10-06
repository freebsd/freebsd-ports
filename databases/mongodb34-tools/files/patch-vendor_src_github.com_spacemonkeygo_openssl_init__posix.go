--- vendor/src/github.com/spacemonkeygo/openssl/init_posix.go.orig	2016-01-03 17:52:58 UTC
+++ vendor/src/github.com/spacemonkeygo/openssl/init_posix.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.

-// +build linux darwin cgo
+// +build linux darwin freebsd cgo
 // +build !windows

 package openssl
@@ -52,7 +52,7 @@ int Goopenssl_init_locks() {
 	return rc;
 }

-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || (OPENSSL_VERSION_NUMBER < 0x10100000L)
 void Goopenssl_thread_locking_callback(int mode, int n, const char *file,
 	int line) {
 	if (mode & CRYPTO_LOCK) {
