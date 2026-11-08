Description: Make odoo-mailgate.py work on Python 3: fall back to
  xmlrpc.client when xmlrpclib is missing, and read the mail from
  stdin as bytes for xmlrpc Binary.
Issue ID: none
Changeset: https://github.com/odoo/odoo/commit/d09d8c5fe3c4 (Python 3
  import fallback, in 19.0; 16.0 to 18.0 still import xmlrpclib).
  Upstream decodes stdin as text, which fails on non-UTF-8 8bit mail;
  this patch reads it as bytes instead.
TODO: Drop when updating to a release with a Python 3 mailgate.

--- odoo/addons/mail/static/scripts/odoo-mailgate.py.orig	2026-06-18 17:00:14 UTC
+++ odoo/addons/mail/static/scripts/odoo-mailgate.py
@@ -19,7 +19,10 @@
 import optparse
 import sys
 import traceback
-import xmlrpclib
+try:
+    import xmlrpclib
+except ImportError:
+    import xmlrpc.client as xmlrpclib
 
 def main():
     op = optparse.OptionParser(usage='usage: %prog [options]', version='%prog v1.2')
@@ -31,7 +34,10 @@ def main():
     (o, args) = op.parse_args()
 
     try:
-        msg = sys.stdin.read()
+        # read raw bytes on python3: xmlrpc Binary needs bytes and mails
+        # may carry 8bit data that is not valid in the locale encoding
+        stdin = getattr(sys.stdin, 'buffer', sys.stdin)
+        msg = stdin.read()
         models = xmlrpclib.ServerProxy('http://%s:%s/xmlrpc/2/object' % (o.host, o.port), allow_none=True)
         models.execute_kw(o.database, o.userid, o.password, 'mail.thread', 'message_process', [False, xmlrpclib.Binary(msg)], {})
     except xmlrpclib.Fault as e:
