--- unix/ibus/ibus.gyp.orig	2013-04-27 19:26:29.000000000 +0900
+++ unix/ibus/ibus.gyp	2013-04-27 19:27:05.000000000 +0900
@@ -134,6 +134,7 @@
                 '--platform=Linux',
                 '--branding=Mozc',
                 '--server_dir=<(server_dir)',
+                '--localbase=<(localbase)',
                 '--pkg_config_command=<(pkg_config_command)',
               ],
             }],
