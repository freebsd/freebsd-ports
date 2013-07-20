--- unix/ibus/selection_monitor.cc.orig	2013-07-20 00:29:25.000000000 +0900
+++ unix/ibus/selection_monitor.cc	2013-07-20 00:37:48.000000000 +0900
@@ -38,6 +38,7 @@
 
 #include "base/logging.h"
 #include "base/mutex.h"
+#include "base/scoped_ptr.h"
 #include "base/thread.h"
 #include "base/port.h"
 #include "base/util.h"
@@ -47,8 +48,6 @@
 
 namespace {
 
-using std::unique_ptr;
-
 class ScopedXcbGenericError {
  public:
   ScopedXcbGenericError()
@@ -69,27 +68,6 @@
   xcb_generic_error_t *error_;
 };
 
-template <typename T>
-struct FreeDeleter {
-  void operator()(T *ptr) const {
-    free(ptr);
-  }
-};
-
-// TODO(yukawa): Use template aliases when GCC 4.6 is retired.
-typedef unique_ptr<xcb_get_property_reply_t,
-                   FreeDeleter<xcb_get_property_reply_t>>
-    ScopedXcbGetPropertyReply;
-typedef unique_ptr<xcb_get_atom_name_reply_t,
-                   FreeDeleter<xcb_get_atom_name_reply_t>>
-    ScopedXcbGetAtomNameReply;
-typedef unique_ptr<xcb_intern_atom_reply_t,
-                   FreeDeleter<xcb_intern_atom_reply_t>>
-    ScopedXcbInternAtomReply;
-typedef unique_ptr<xcb_xfixes_query_version_reply_t,
-                   FreeDeleter<xcb_xfixes_query_version_reply_t>>
-    ScopedXcbXFixesQueqyVersionReply;
-
 struct XcbAtoms {
   xcb_atom_t mozc_selection_monitor;
   xcb_atom_t net_wm_name;
@@ -231,7 +209,7 @@
     *atom = XCB_NONE;
     xcb_intern_atom_cookie_t cookie =
         ::xcb_intern_atom(connection_, false, name.size(), name.c_str());
-    ScopedXcbInternAtomReply reply(
+    scoped_ptr_malloc<xcb_intern_atom_reply_t> reply(
         ::xcb_intern_atom_reply(connection_, cookie, 0));
     if (reply.get() == NULL) {
       LOG(ERROR) << "xcb_intern_atom_reply returned NULL reply.";
@@ -267,7 +245,7 @@
             XCB_XFIXES_MAJOR_VERSION,
             XCB_XFIXES_MINOR_VERSION);
     ScopedXcbGenericError xcb_error;
-    ScopedXcbXFixesQueqyVersionReply xfixes_query(
+    scoped_ptr_malloc<xcb_xfixes_query_version_reply_t> xfixes_query(
         ::xcb_xfixes_query_version_reply(
             connection_, xfixes_query_cookie, xcb_error.mutable_get()));
     if (xcb_error.get() != NULL) {
@@ -298,7 +276,7 @@
     const xcb_get_atom_name_cookie_t cookie = ::xcb_get_atom_name(
         connection_, atom);
     ScopedXcbGenericError xcb_error;
-    ScopedXcbGetAtomNameReply reply(
+    scoped_ptr_malloc<xcb_get_atom_name_reply_t> reply(
         ::xcb_get_atom_name_reply(
             connection_, cookie, xcb_error.mutable_get()));
     if (xcb_error.get() != NULL) {
@@ -331,7 +309,7 @@
                              property_atom,
                              property_type_atom,
                              0, 0);
-      ScopedXcbGetPropertyReply reply(
+      scoped_ptr_malloc<xcb_get_property_reply_t> reply(
           ::xcb_get_property_reply(connection_, cookie, 0));
       if (reply.get() == NULL) {
         VLOG(2) << "reply is NULL";
@@ -378,7 +356,7 @@
                              property_type_atom,
                              byte_offset,
                              max_bytes);
-      ScopedXcbGetPropertyReply reply(
+      scoped_ptr_malloc<xcb_get_property_reply_t> reply(
           ::xcb_get_property_reply(connection_, cookie, 0));
       if (reply.get() == NULL) {
         VLOG(2) << "reply is NULL";
@@ -408,7 +386,7 @@
                            property_atom,
                            XCB_ATOM_CARDINAL,
                            0, sizeof(T) * 8);
-    ScopedXcbGetPropertyReply reply(
+    scoped_ptr_malloc<xcb_get_property_reply_t> reply(
         ::xcb_get_property_reply(connection_, cookie, 0));
     if (reply.get() == NULL) {
       VLOG(2) << "reply is NULL";
