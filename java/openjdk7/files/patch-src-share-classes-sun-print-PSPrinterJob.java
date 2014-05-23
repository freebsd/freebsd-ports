--- jdk/src/share/classes/sun/print/PSPrinterJob.java
+++ jdk/src/share/classes/sun/print/PSPrinterJob.java
@@ -1568,9 +1568,31 @@
         }
 
        String osname = System.getProperty("os.name");
-       if (osname.equals("Linux") || osname.equals("FreeBSD") || osname.equals("NetBSD") || osname.equals("OpenBSD") || osname.equals("OS X")) {
+       if (osname.equals("Linux") || osname.endsWith("BSD") || osname.contains("OS X")) {
+            String lprPath = "/usr/bin/lpr";
+            if (osname.endsWith("BSD")) {
+                final PrintService pservice = getPrintService();
+                Boolean isIPPPrinter =
+                    (Boolean)java.security.AccessController.doPrivileged(
+                    new java.security.PrivilegedAction() {
+                        public Object run() {
+                            try {
+                                Class psClass =
+                                    Class.forName("sun.print.IPPPrintService");
+                                if (psClass.isInstance(pservice)) {
+                                    return Boolean.TRUE;
+                                }
+                            } catch (Throwable t) {
+                            }
+                            return Boolean.FALSE;
+                        }
+                    });
+                if (isIPPPrinter) {
+                    lprPath = "%%LOCALBASE%%/bin/lpr";
+                }
+            }
             execCmd = new String[ncomps];
-            execCmd[n++] = "/usr/bin/lpr";
+            execCmd[n++] = lprPath;
             if ((pFlags & PRINTER) != 0) {
                 execCmd[n++] = "-P" + printer;
             }
