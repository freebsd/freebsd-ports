--- server/gam_kqueue.h.orig	Fri Apr  8 14:50:41 2005
+++ server/gam_kqueue.h	Fri Apr  8 14:51:01 2005
@@ -0,0 +1,16 @@
+#ifndef __MD_KQUEUE_H__
+#define __MD_KQUEUE_H__
+
+#include <glib.h>
+#include "gam_subscription.h"
+
+G_BEGIN_DECLS
+
+gboolean   gam_kqueue_init                  (void);
+gboolean   gam_kqueue_add_subscription      (GamSubscription *sub);
+gboolean   gam_kqueue_remove_subscription   (GamSubscription *sub);
+gboolean   gam_kqueue_remove_all_for        (GamListener *listener);
+
+G_END_DECLS
+
+#endif /* __MD_KQUEUE_H__ */
