--- include/my_libwrap.h.orig	Tue Nov  7 08:39:53 2006
+++ include/my_libwrap.h	Tue Nov  7 08:40:17 2006
@@ -15,7 +15,7 @@
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */
 
 #ifdef HAVE_LIBWRAP
-#include <tcpd.h>
+#include <my_tcpd.h>
 #include <syslog.h>
 #ifdef NEED_SYS_SYSLOG_H
 #include <sys/syslog.h>
