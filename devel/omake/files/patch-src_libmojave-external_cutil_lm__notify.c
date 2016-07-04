$NetBSD: patch-ak,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_notify.c.orig	2007-07-27 17:58:13.000000000 +0000
+++ src/libmojave-external/cutil/lm_notify.c
@@ -74,13 +74,13 @@ typedef struct {
 
 #define CheckCode(fmt, expr)                 \
   do {                                       \
-     enter_blocking_section();               \
+     caml_enter_blocking_section();               \
      code = expr;                            \
-     leave_blocking_section();               \
+     caml_leave_blocking_section();               \
      if(code < 0) {                          \
          char buffer[256];                   \
          ErrFmt(buffer, fmt);                \
-         failwith(buffer);                   \
+         caml_failwith(buffer);                   \
      }                                       \
   } while(0)
 
@@ -145,11 +145,11 @@ value om_notify_open(value v_unit)
     FAMInfo *info;
     int code;
 
-    v = alloc_custom(&fam_connection_ops, sizeof(FAMInfo), 0, 1);
+    v = caml_alloc_custom(&fam_connection_ops, sizeof(FAMInfo), 0, 1);
     info = FAMInfo_val(v);
     fc = malloc(sizeof(FAMConnection));
     if(fc == 0)
-        invalid_argument("om_notify_open: out of memory");
+        caml_invalid_argument("om_notify_open: out of memory");
     info->fc = fc;
     CheckCode("om_notify_open", FAMOpen(fc));
 #ifdef HAVE_FAMNOEXISTS
@@ -180,7 +180,7 @@ value om_notify_fd(value v_fc)
     fc = FAMConnection_val(v_fc);
     return Val_int(fc->id);
 #else /* FAM_PSEUDO && !FAM_INOTIFY */
-    failwith("No file descriptors in pseudo-FAM");
+    caml_failwith("No file descriptors in pseudo-FAM");
     return Val_unit;
 #endif /* FAM_INOTIFY */
 #else /* FAM_PSEUDO */
@@ -209,7 +209,7 @@ value om_notify_monitor_directory(value 
 #ifdef WIN32
         CheckCode("om_notify_monitor_directory", FAMMonitorDirectoryTree(fc, name, &request, 0));
 #else /* WIN32 */
-        failwith("om_notify_monitor_directory: recursive monitoring is not allowed");
+        caml_failwith("om_notify_monitor_directory: recursive monitoring is not allowed");
 #endif /* !WIN32 */
     }
     else
@@ -294,13 +294,13 @@ value om_notify_next_event(value v_fc)
     CheckCode("om_notify_next_event", FAMNextEvent(fc, &event));
     code = event.code;
     if(code < 1 || code > 10)
-        failwith("om_notify_next_event: code out of bounds");
+        caml_failwith("om_notify_next_event: code out of bounds");
 
     /* Allocate the string name */
-    v_name = copy_string(event.filename);
+    v_name = caml_copy_string(event.filename);
 
     /* Allocate the tuple */
-    v_tuple = alloc_tuple(3);
+    v_tuple = caml_alloc_tuple(3);
     Field(v_tuple, 0) = Val_int(event.fr.reqnum);
     Field(v_tuple, 1) = v_name;
     Field(v_tuple, 2) = Val_int(code - 1);
@@ -330,7 +330,7 @@ value om_notify_open(value v_unit)
  */
 value om_notify_fd(value v_fc)
 {
-    invalid_argument("FAM not enabled");
+    caml_invalid_argument("FAM not enabled");
     return Val_unit;
 }
 
@@ -389,7 +389,7 @@ value om_notify_pending(value v_fc)
  */
 value om_notify_next_event(value v_fc)
 {
-    invalid_argument("FAM not enabled");
+    caml_invalid_argument("FAM not enabled");
     return Val_unit;
 }
 
