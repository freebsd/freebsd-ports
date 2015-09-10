--- src/unix/ibus/ibus.gyp.orig	2015-02-17 18:04:40.000000000 +0900
+++ src/unix/ibus/ibus.gyp	2015-02-17 18:04:58.000000000 +0900
@@ -83,6 +83,8 @@
             './gen_mozc_xml.py',
             '--branding=Mozc',
             '--server_dir=<(server_dir)',
+            '--renderer_dir=<(renderer_dir)',
+            '--tool_dir=<(tool_dir)',
             '--pkg_config_command=<(pkg_config_command)',
             '--ibus_mozc_path=<(ibus_mozc_path)',
             '--ibus_mozc_icon_path=<(ibus_mozc_icon_path)',
