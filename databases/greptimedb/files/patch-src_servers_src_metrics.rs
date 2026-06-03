--- src/servers/src/metrics.rs.orig	2026-04-09 01:24:45 UTC
+++ src/servers/src/metrics.rs
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-#[cfg(not(windows))]
+#[cfg(not(any(windows, target_os = "freebsd")))]
 pub(crate) mod jemalloc;
 
 use std::task::{Context, Poll};
