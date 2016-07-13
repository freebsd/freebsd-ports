--- src/rtapi/uspace_rtapi_parport.cc.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/uspace_rtapi_parport.cc
@@ -13,6 +13,7 @@
 //    You should have received a copy of the GNU General Public License
 //    along with this program; if not, write to the Free Software
 //    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+#ifdef __linux__
 #include <errno.h>
 #include <fcntl.h>
 #include <linux/ppdev.h>
@@ -120,3 +121,4 @@ void rtapi_parport_release(rtapi_parport
     close(port->fd);
     port->fd = -1;
 }
+#endif /* __linux__ */
