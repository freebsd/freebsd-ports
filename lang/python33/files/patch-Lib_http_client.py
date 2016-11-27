Based on and adapted for Python 3.3: https://hg.python.org/cpython/rev/bf3e1c9b80e9
# HG changeset patch
# User Serhiy Storchaka <storchaka@gmail.com>
# Date 1426151616 -7200
# Node ID bf3e1c9b80e995311ba932e42200f076e03034c0
# Parent  2b4a04c3681b1210529eb8a224cc007a0b92a890
Issue #22928: Disabled HTTP header injections in http.client.
Original patch by Demian Brecht.

--- Lib/http/client.py.orig	2016-06-30 21:29:02 UTC
+++ Lib/http/client.py
@@ -70,6 +70,7 @@ import email.parser
 import email.message
 import io
 import os
+import re
 import socket
 import collections
 from urllib.parse import urlsplit
@@ -216,6 +217,35 @@ MAXAMOUNT = 1048576
 _MAXLINE = 65536
 _MAXHEADERS = 100
 
+# Header name/value ABNF (http://tools.ietf.org/html/rfc7230#section-3.2)
+#
+# VCHAR          = %x21-7E
+# obs-text       = %x80-FF
+# header-field   = field-name ":" OWS field-value OWS
+# field-name     = token
+# field-value    = *( field-content / obs-fold )
+# field-content  = field-vchar [ 1*( SP / HTAB ) field-vchar ]
+# field-vchar    = VCHAR / obs-text
+#
+# obs-fold       = CRLF 1*( SP / HTAB )
+#                ; obsolete line folding
+#                ; see Section 3.2.4
+
+# token          = 1*tchar
+#
+# tchar          = "!" / "#" / "$" / "%" / "&" / "'" / "*"
+#                / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
+#                / DIGIT / ALPHA
+#                ; any VCHAR, except delimiters
+#
+# VCHAR defined in http://tools.ietf.org/html/rfc5234#appendix-B.1
+
+# the patterns for both name and value are more leniant than RFC
+# definitions to allow for backwards compatibility
+_is_legal_header_name = re.compile(rb'^[^:\s][^:\r\n]*$').match
+_is_illegal_header_value = re.compile(rb'\n(?![ \t])|\r(?![ \t\n])').search
+
+
 
 class HTTPMessage(email.message.Message):
     # XXX The only usage of this method is in
@@ -1035,12 +1065,20 @@ class HTTPConnection:
 
         if hasattr(header, 'encode'):
             header = header.encode('ascii')
+
+        if not _is_legal_header_name(header):
+            raise ValueError('Invalid header name %r' % (header,))
+
         values = list(values)
         for i, one_value in enumerate(values):
             if hasattr(one_value, 'encode'):
                 values[i] = one_value.encode('latin-1')
             elif isinstance(one_value, int):
                 values[i] = str(one_value).encode('ascii')
+
+            if _is_illegal_header_value(values[i]):
+                raise ValueError('Invalid header value %r' % (values[i],))
+
         value = b'\r\n\t'.join(values)
         header = header + b': ' + value
         self._output(header)
