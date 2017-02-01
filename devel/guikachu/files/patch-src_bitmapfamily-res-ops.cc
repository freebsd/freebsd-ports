--- src/bitmapfamily-res-ops.cc.orig	2006-10-06 22:35:39 UTC
+++ src/bitmapfamily-res-ops.cc
@@ -28,7 +28,7 @@ using namespace Guikachu::ResourceOps::B
 namespace {
     Glib::ustring translate_tagged_string (const char *msgid)
     {
-        char *msgval = gettext (msgid);
+        const char *msgval = gettext (msgid);
         if (msgval == msgid)
             msgval = strrchr (msgid, '|') + 1;
         return msgval;
