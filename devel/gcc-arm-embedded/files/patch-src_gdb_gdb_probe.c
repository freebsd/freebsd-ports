--- src/gdb/gdb/probe.c.orig	2018-01-24 19:30:20.436713000 +0300
+++ src/gdb/gdb/probe.c	2018-01-24 19:30:41.659782000 +0300
@@ -43,6 +43,8 @@
 class any_static_probe_ops : public static_probe_ops
 {
 public:
+  any_static_probe_ops() {}
+
   /* See probe.h.  */
   bool is_linespec (const char **linespecp) const override;
 
