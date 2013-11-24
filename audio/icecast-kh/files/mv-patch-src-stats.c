--- src/stats.c.orig	2008-05-01 10:22:40.000000000 +0800
+++ src/stats.c	2012-04-24 02:22:44.574821557 +0800
@@ -973,7 +973,11 @@
                 if (event->source)
                 {
                     if (show_mount && strcmp (event->source, show_mount) != 0)
+                    {
+                        xmlFree (name);
+                        xmlFree (value);
                         break;
+                    }
                     srcnode = _find_xml_node(event->source, &src_nodes, node);
                 }
                 else
