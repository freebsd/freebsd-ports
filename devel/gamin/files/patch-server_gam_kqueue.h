--- server/gam_kqueue.h.orig	Thu May 19 20:35:00 2005
+++ server/gam_kqueue.h	Thu May 19 20:35:11 2005
@@ -1,16 +1,8 @@
-
 #ifndef __MD_KQUEUE_H__
 #define __MD_KQUEUE_H__
 
 #include <glib.h>
-#include "gam_poll.h"
 #include "gam_subscription.h"
-
-#define VN_NOTE_MOST	(NOTE_DELETE | NOTE_WRITE | NOTE_EXTEND | \
-			 NOTE_ATTRIB | NOTE_LINK | NOTE_RENAME | \
-			 NOTE_REVOKE)
-#define VN_NOTE_ALL	VN_NOTE_MOST
-#define VN_NOTE_CHANGED	(NOTE_WRITE | NOTE_EXTEND | NOTE_ATTRIB | NOTE_LINK)
 
 G_BEGIN_DECLS
 
