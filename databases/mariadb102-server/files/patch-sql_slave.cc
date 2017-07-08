--- sql/slave.cc.orig	2017-05-14 23:13:18 UTC
+++ sql/slave.cc
@@ -14,6 +14,11 @@
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#define ERR_remove_state(X)
+#elif defined(HAVE_ERR_remove_thread_state)
+#define ERR_remove_state(X) ERR_remove_thread_state(NULL)
+#endif
 
 /**
   @addtogroup Replication
