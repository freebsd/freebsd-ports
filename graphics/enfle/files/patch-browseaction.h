--- browseaction.h.orig	Wed Jun 28 03:19:49 2000
+++ browseaction.h	Fri Dec  5 15:35:56 2003
@@ -29,7 +29,7 @@
 
 int browseaction_initialize(Hash *);
 
-#define DECLARE_BROWSEACTION(name) Event browseaction_ ## name ## (Info *, Binfo *, Image *, Dlist_data *)
+#define DECLARE_BROWSEACTION(name) Event browseaction_ ## name (Info *, Binfo *, Image *, Dlist_data *)
 DECLARE_BROWSEACTION(delete);
 DECLARE_BROWSEACTION(quit);
 DECLARE_BROWSEACTION(flip_vertical);
