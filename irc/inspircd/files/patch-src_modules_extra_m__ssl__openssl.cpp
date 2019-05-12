--- src/modules/extra/m_ssl_openssl.cpp.orig	2019-05-08 13:19:20 UTC
+++ src/modules/extra/m_ssl_openssl.cpp
@@ -21,7 +21,7 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
-/// $CompilerFlags: find_compiler_flags("openssl")
+/// $CompilerFlags: find_compiler_flags("openssl" "")
 /// $LinkerFlags: find_linker_flags("openssl" "-lssl -lcrypto")
 
 /// $PackageInfo: require_system("centos") openssl-devel pkgconfig
