
$FreeBSD$

--- amarok/src/mediabrowser.h.orig
+++ amarok/src/mediabrowser.h
@@ -19,11 +19,11 @@
 #include <kurl.h>            //stack allocated
 #include <kio/global.h>      //filesize_t
 #include "scrobbler.h"       //SubmitItem
+#include "metabundle.h"
 
 class MediaBrowser;
 class MediaDevice;
 class MediaView;
-class MetaBundle;
 class SpaceLabel;
 class TransferDialog;
 
