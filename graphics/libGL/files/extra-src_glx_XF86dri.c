--- src/glx/XF86dri.c.orig	2012-10-24 19:03:59.000000000 +0000
+++ src/glx/XF86dri.c	2013-05-29 10:07:33.000000000 +0000
@@ -43,6 +43,7 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN
 #include <X11/extensions/Xext.h>
 #include <X11/extensions/extutil.h>
 #include "xf86dristr.h"
+#include <limits.h>
 
 static XExtensionInfo _xf86dri_info_data;
 static XExtensionInfo *xf86dri_info = &_xf86dri_info_data;
@@ -201,7 +202,11 @@ XF86DRIOpenConnection(Display * dpy, int
    }
 
    if (rep.length) {
-      if (!(*busIdString = (char *) Xcalloc(rep.busIdStringLength + 1, 1))) {
+      if (rep.busIdStringLength < INT_MAX)
+	 *busIdString = Xcalloc(rep.busIdStringLength + 1, 1);
+      else
+	 *busIdString = NULL;
+      if (*busIdString == NULL) {
          _XEatData(dpy, ((rep.busIdStringLength + 3) & ~3));
          UnlockDisplay(dpy);
          SyncHandle();
@@ -300,9 +305,11 @@ XF86DRIGetClientDriverName(Display * dpy
    *ddxDriverPatchVersion = rep.ddxDriverPatchVersion;
 
    if (rep.length) {
-      if (!
-          (*clientDriverName =
-           (char *) Xcalloc(rep.clientDriverNameLength + 1, 1))) {
+      if (rep.clientDriverNameLength < INT_MAX)
+	 *clientDriverName = Xcalloc(rep.clientDriverNameLength + 1, 1);
+      else
+	 *clientDriverName = NULL;
+      if (*clientDriverName == NULL) {
          _XEatData(dpy, ((rep.clientDriverNameLength + 3) & ~3));
          UnlockDisplay(dpy);
          SyncHandle();
