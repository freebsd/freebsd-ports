--- setup/gen_driver_freebsd.inc.orig	2022-07-26 19:01:18 UTC
+++ setup/gen_driver_freebsd.inc
@@ -233,9 +233,15 @@ generate_driver (char *name, conf_t * conf, char *cfg_
       fprintf (src,
 	       "DEFINE_CLASS_0(%s, osspci_driver, osspci_methods, sizeof(struct _oss_device_t));\n",
 	       name);
+      fprintf (src, "#if __FreeBSD_version >= 1400058\n");
       fprintf (src,
+	       "DRIVER_MODULE(%s, pci, osspci_driver, 0, 0);\n",
+	       name);
+      fprintf (src, "#else\n");
+      fprintf (src,
 	       "DRIVER_MODULE(%s, pci, osspci_driver, osspci_devclass, 0, 0);\n",
 	       name);
+      fprintf (src, "#endif\n");
     }
 
   for (i = 0; i < nopts; i++)
