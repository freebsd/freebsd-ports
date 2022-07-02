--- libexec/got-read-blob/got-read-blob.c.orig	2022-06-19 18:47:42 UTC
+++ libexec/got-read-blob/got-read-blob.c
@@ -14,6 +14,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <sys/capsicum.h>
 #include <sys/types.h>
 #include <sys/queue.h>
 #include <sys/uio.h>
@@ -65,6 +66,11 @@ main(int argc, char *argv[])
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
