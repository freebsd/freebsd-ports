--- src/gdb/gdb/dtrace-probe.c.orig	2018-01-23 21:30:27.712651000 +0300
+++ src/gdb/gdb/dtrace-probe.c	2018-01-23 21:30:46.183643000 +0300
@@ -77,6 +77,8 @@
 class dtrace_static_probe_ops : public static_probe_ops
 {
 public:
+  dtrace_static_probe_ops() {}
+
   /* See probe.h.  */
   bool is_linespec (const char **linespecp) const override;
 
