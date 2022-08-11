--- libexec/got-read-pack/got-read-pack.c.orig	2022-07-04 14:48:30 UTC
+++ libexec/got-read-pack/got-read-pack.c
@@ -14,6 +14,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <sys/capsicum.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/queue.h>
@@ -1917,6 +1918,11 @@ main(int argc, char *argv[])
 	/* revoke access to most system calls */
 	if (pledge("stdio recvfd", NULL) == -1) {
 		err = got_error_from_errno("pledge");
+		got_privsep_send_error(&ibuf, err);
+		return 1;
+	}
+	if (cap_enter() == -1) {
+		err = got_error_from_errno("cap_enter");
 		got_privsep_send_error(&ibuf, err);
 		return 1;
 	}
