--- src/calibre/devices/scanner.py.orig	2010-10-06 22:06:18.000000000 -0700
+++ src/calibre/devices/scanner.py	2010-10-06 22:07:36.000000000 -0700
@@ -5,10 +5,10 @@
 manner.
 '''
 
-import sys, os, re
+import sys, os, re, subprocess
 from threading import RLock
 
-from calibre import iswindows, isosx, plugins, islinux
+from calibre import iswindows, isosx, plugins, islinux, isfreebsd
 
 osx_scanner = win_scanner = linux_scanner = None
 
@@ -140,17 +140,65 @@
             ans.add(tuple(dev))
         return ans
 
+class FreeBSDScanner(object):
+
+    def __call__(self):
+        ans = set([])
+
+        try:
+            out = subprocess.Popen("/usr/sbin/usbconfig dump_device_desc | /usr/bin/awk 'function get_str(s) { split(s, a, /<|>/); if (a[2] != \"no string\") { return a[2]; } else { return \"\";} } BEGIN {state=0;} /^[[:space:]]+idVendor/ {state = 1; vendor = $3; next;} /idProduct/ {productid = $3; next;} /bcdDevice/ {bcd = $3; next;} /iManufacturer/ { manufacturer = get_str($0); next; }  /iProduct/ { product = get_str($0); next;} /iSerialNumber/ { sn = get_str($0); next;} /^$/ {if (state == 1) { state = 0; printf(\"%s%%%%%s%%%%%s%%%%%s%%%%%s%%%%%s\\n\",vendor, productid, bcd, manufacturer, product, sn);} }'", shell=True, stdout=subprocess.PIPE).communicate()[0]
+        except OSError, e:
+	    print >>sys.stderr, "Execution failed:", e
+
+        if out.strip() == "":
+            return ans
+        for line in out.strip().split("\n"):
+            ven, prod, bcd, man, prod_string, serial = line.strip().split("%%", 6)
+            dev = []
+            try:
+                dev.append(int(ven, 16))
+            except:
+                continue
+            try:
+                dev.append(int(prod, 16))
+            except:
+                continue
+            try:
+                dev.append(int(bcd, 16))
+            except:
+                continue
+            try:
+                dev.append(man)
+            except:
+                dev.append('')
+            try:
+                dev.append(prod_string)
+            except:
+                dev.append('')
+            try:
+                dev.append(serial)
+            except:
+                dev.append('')
+
+            ans.add(tuple(dev))
+        return ans
+
 linux_scanner = None
 
 if islinux:
     linux_scanner = LinuxScanner()
 
+freebsd_scanner = None
+
+if isfreebsd:
+    freebsd_scanner = FreeBSDScanner()
+
 class DeviceScanner(object):
 
     def __init__(self, *args):
         if isosx and osx_scanner is None:
             raise RuntimeError('The Python extension usbobserver must be available on OS X.')
-        self.scanner = win_scanner if iswindows else osx_scanner if isosx else linux_scanner
+        self.scanner = win_scanner if iswindows else osx_scanner if isosx else freebsd_scanner if isfreebsd else linux_scanner
         self.devices = []
 
     def scan(self):
