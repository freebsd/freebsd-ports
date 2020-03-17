--- src/gdb/gdb/stap-probe.c.orig	2019-10-30 01:03:58 UTC
+++ src/gdb/gdb/stap-probe.c
@@ -102,6 +102,8 @@ struct stap_probe_arg
 class stap_static_probe_ops : public static_probe_ops
 {
 public:
+  stap_static_probe_ops() {}
+
   /* See probe.h.  */
   bool is_linespec (const char **linespecp) const override;
 
