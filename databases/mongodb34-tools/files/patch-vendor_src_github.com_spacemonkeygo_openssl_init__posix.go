--- vendor/src/github.com/spacemonkeygo/openssl/init_posix.go.orig	2016-01-03 17:52:58 UTC
+++ vendor/src/github.com/spacemonkeygo/openssl/init_posix.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-// +build linux darwin cgo
+// +build linux darwin freebsd cgo
 // +build !windows
 
 package openssl
