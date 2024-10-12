--- bugzilla/_cli.py.orig	2024-09-23 07:35:49 UTC
+++ bugzilla/_cli.py
@@ -29,7 +29,7 @@ import bugzilla
 import bugzilla
 
 
-DEFAULT_BZ = 'https://bugzilla.redhat.com'
+DEFAULT_BZ = 'https://bugs.freebsd.org/bugzilla/xmlrpc.cgi'
 
 format_field_re = re.compile("%{([a-z0-9_]+)(?::([^}]*))?}")
 
