--- src/gdb/gdb/dtrace-probe.c.orig	2019-10-26 00:03:38 UTC
+++ src/gdb/gdb/dtrace-probe.c
@@ -77,6 +77,8 @@ struct dtrace_probe_enabler
 class dtrace_static_probe_ops : public static_probe_ops
 {
 public:
+  dtrace_static_probe_ops() {}
+
   /* See probe.h.  */
   bool is_linespec (const char **linespecp) const override;
 
