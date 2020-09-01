--- bugzilla/_cli.py.orig	2020-07-04 17:39:54 UTC
+++ bugzilla/_cli.py
@@ -31,7 +31,7 @@ from bugzilla._compatimports import Fault, ProtocolErr
 from bugzilla._util import to_encoding
 
 
-DEFAULT_BZ = 'https://bugzilla.redhat.com'
+DEFAULT_BZ = 'https://bugs.freebsd.org/bugzilla/xmlrpc.cgi'
 
 format_field_re = re.compile("%{([a-z0-9_]+)(?::([^}]*))?}")
 
