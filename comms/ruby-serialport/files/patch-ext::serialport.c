--- ext/serialport.c.orig	2009-07-30 12:57:44.000000000 +0400
+++ ext/serialport.c	2009-07-30 13:00:20.000000000 +0400
@@ -126,6 +126,7 @@
  * Set the state (0 or 1) of the DTR line
  */
 static VALUE sp_set_dtr(self, val)
+   VALUE self, val;
 {
    return sp_set_dtr_impl(self, val);
 }
@@ -138,6 +139,7 @@
  *  supported.
  */
 static VALUE sp_set_flow_control(self, val)
+   VALUE self, val;
 {
    return sp_set_flow_control_impl(self, val);
 }
@@ -153,6 +155,7 @@
  * Note: Read timeouts don't mix well with multi-threading.
  */
 static VALUE sp_set_read_timeout(self, val)
+   VALUE self, val;
 {
    return sp_set_read_timeout_impl(self, val);
 }
@@ -161,6 +164,7 @@
  * Set the state (0 or 1) of the RTS line
  */
 static VALUE sp_set_rts(self, val)
+   VALUE self, val;
 {
    return sp_set_rts_impl(self, val);
 }
@@ -171,6 +175,7 @@
  * Note: Under Posix, write timeouts are not implemented.
  */
 static VALUE sp_set_write_timeout(self, val)
+   VALUE self, val;
 {
    return sp_set_write_timeout_impl(self, val);
 }
