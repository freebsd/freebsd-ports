--- setup.py.orig	2003-09-05 12:25:18.000000000 +0800
+++ setup.py	2008-03-17 12:42:43.000000000 +0800
@@ -1,6 +1,6 @@
 #!/usr/bin/env python
 
-import sys
+import sys, os
 
 if sys.hexversion < 0x02020000:
     print
@@ -46,7 +46,7 @@
     print
     print '   see http://www.pythonware.com/products/pil/'
     print
-    if not get_yesno( 'Do you want to continue installing? [Y/n] ', 1 ):
+    if False:
         print
         print 'Installation cancelled.'
         print
@@ -59,7 +59,7 @@
 print 'To use "epstoimg" you will need the Ghostscript interpreter'
 print 'installed.  (see http://www.ghostscript.com/)'
 print
-if get_yesno( 'Do you want to install epstoimg? [Y/n] ', 1 ):
+if True:
     if sys.platform == 'win32':
         default = '+gswin32c.exe'
     else:
@@ -68,7 +68,9 @@
     print
     print 'Enter the full pathname of the Ghostscript interpreter,'
     print 'or "+foo" to search the PATH for "foo" at runtime:'
-    gs = raw_input( '[%s] ' % (default,) )
+    # gs = raw_input( '[%s] ' % (default,) )
+    gs = os.environ['PREFIX'] + '/bin/gs'
+    print "ghostscript: " + gs
     if gs == '':
         gs = default
 
