--- Mailman/Cgi/private.py.orig	2010-09-21 03:18:27.000000000 +0900
+++ Mailman/Cgi/private.py	2011-04-08 22:28:09.000000000 +0900
@@ -116,6 +116,7 @@
 
     i18n.set_language(mlist.preferred_language)
     doc.set_language(mlist.preferred_language)
+    is_cgi = 0
 
     cgidata = cgi.FieldStorage()
     username = cgidata.getvalue('username', '')
@@ -179,6 +180,10 @@
         elif true_filename.endswith('.gz'):
             import gzip
             f = gzip.open(true_filename, 'r')
+        elif true_filename.endswith('namazu.cgi'):
+            os.putenv('SCRIPT_NAME', 'namazu.cgi')
+            f = os.popen(true_filename, 'r')
+            is_cgi = 1
         else:
             f = open(true_filename, 'r')
     except IOError:
@@ -188,6 +193,7 @@
         print doc.Format()
         syslog('error', 'Private archive file not found: %s', true_filename)
     else:
-        print 'Content-type: %s\n' % ctype
+        if not is_cgi:
+            print 'Content-type: %s\n' % ctype
         sys.stdout.write(f.read())
         f.close()
