--- src/gdb/gdb/probe.c.orig	2019-10-26 00:03:38 UTC
+++ src/gdb/gdb/probe.c
@@ -43,6 +43,8 @@
 class any_static_probe_ops : public static_probe_ops
 {
 public:
+  any_static_probe_ops() {}
+
   /* See probe.h.  */
   bool is_linespec (const char **linespecp) const override;
 
