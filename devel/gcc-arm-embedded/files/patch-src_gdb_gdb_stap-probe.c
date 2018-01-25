--- src/gdb/gdb/stap-probe.c.orig	2018-01-23 18:50:38.886661000 +0300
+++ src/gdb/gdb/stap-probe.c	2018-01-23 18:51:08.013663000 +0300
@@ -102,6 +102,8 @@
 class stap_static_probe_ops : public static_probe_ops
 {
 public:
+  stap_static_probe_ops() {}
+
   /* See probe.h.  */
   bool is_linespec (const char **linespecp) const override;
 
