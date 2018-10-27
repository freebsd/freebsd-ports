--- lib/c_attach.cc.orig	2018-10-19 21:02:54 UTC
+++ lib/c_attach.cc
@@ -27,7 +27,7 @@
 /*--------------------------------------------------------------------------*/
 namespace {
 /*--------------------------------------------------------------------------*/
-std::map<const std::string, void*> attach_list;
+std::map<std::string, void*> attach_list;
 /*--------------------------------------------------------------------------*/
 class CMD_ATTACH : public CMD {
 public:
