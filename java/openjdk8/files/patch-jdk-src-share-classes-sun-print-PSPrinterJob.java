--- .jdk/src/share/classes/sun/print/PSPrinterJob.java.orig	2015-07-18 14:45:27.000000000 -0700
+++ jdk/src/share/classes/sun/print/PSPrinterJob.java	2015-07-18 14:50:32.000000000 -0700
@@ -1607,7 +1607,7 @@
                         }
                     });
                 if (isIPPPrinter) {
-                    lprPath = "/usr/local/bin/lpr";
+                    lprPath = "%%LOCALBASE%%/bin/lpr";
                 }
             }
             execCmd = new String[ncomps];
