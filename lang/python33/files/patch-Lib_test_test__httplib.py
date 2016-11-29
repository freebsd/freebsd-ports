Based on and adapted for Python 3.3: https://hg.python.org/cpython/rev/bf3e1c9b80e9
# HG changeset patch
# User Serhiy Storchaka <storchaka@gmail.com>
# Date 1426151616 -7200
# Node ID bf3e1c9b80e995311ba932e42200f076e03034c0
# Parent  2b4a04c3681b1210529eb8a224cc007a0b92a890
Issue #22928: Disabled HTTP header injections in http.client.
Original patch by Demian Brecht.

--- Lib/test/test_httplib.py.orig	2016-06-30 21:31:29 UTC
+++ Lib/test/test_httplib.py
@@ -134,6 +134,33 @@ class HeaderTests(TestCase):
         conn.putheader('Content-length', 42)
         self.assertIn(b'Content-length: 42', conn._buffer)
 
+        conn.putheader('Foo', ' bar ')
+        self.assertIn(b'Foo:  bar ', conn._buffer)
+        conn.putheader('Bar', '\tbaz\t')
+        self.assertIn(b'Bar: \tbaz\t', conn._buffer)
+        conn.putheader('Authorization', 'Bearer mytoken')
+        self.assertIn(b'Authorization: Bearer mytoken', conn._buffer)
+        conn.putheader('IterHeader', 'IterA', 'IterB')
+        self.assertIn(b'IterHeader: IterA\r\n\tIterB', conn._buffer)
+        conn.putheader('LatinHeader', b'\xFF')
+        self.assertIn(b'LatinHeader: \xFF', conn._buffer)
+        conn.putheader('Utf8Header', b'\xc3\x80')
+        self.assertIn(b'Utf8Header: \xc3\x80', conn._buffer)
+        conn.putheader('C1-Control', b'next\x85line')
+        self.assertIn(b'C1-Control: next\x85line', conn._buffer)
+        conn.putheader('Embedded-Fold-Space', 'is\r\n allowed')
+        self.assertIn(b'Embedded-Fold-Space: is\r\n allowed', conn._buffer)
+        conn.putheader('Embedded-Fold-Tab', 'is\r\n\tallowed')
+        self.assertIn(b'Embedded-Fold-Tab: is\r\n\tallowed', conn._buffer)
+        conn.putheader('Key Space', 'value')
+        self.assertIn(b'Key Space: value', conn._buffer)
+        conn.putheader('KeySpace ', 'value')
+        self.assertIn(b'KeySpace : value', conn._buffer)
+        conn.putheader(b'Nonbreak\xa0Space', 'value')
+        self.assertIn(b'Nonbreak\xa0Space: value', conn._buffer)
+        conn.putheader(b'\xa0NonbreakSpace', 'value')
+        self.assertIn(b'\xa0NonbreakSpace: value', conn._buffer)
+
     def test_ipv6host_header(self):
         # Default host header on IPv6 transaction should wrapped by [] if
         # its actual IPv6 address
@@ -153,6 +180,34 @@ class HeaderTests(TestCase):
         conn.request('GET', '/foo')
         self.assertTrue(sock.data.startswith(expected))
 
+    def test_invalid_headers(self):
+        conn = client.HTTPConnection('example.com')
+        conn.sock = FakeSocket('')
+        conn.putrequest('GET', '/')
+
+        # http://tools.ietf.org/html/rfc7230#section-3.2.4, whitespace is no
+        # longer allowed in header names
+        cases = (
+            (b'Invalid\r\nName', b'ValidValue'),
+            (b'Invalid\rName', b'ValidValue'),
+            (b'Invalid\nName', b'ValidValue'),
+            (b'\r\nInvalidName', b'ValidValue'),
+            (b'\rInvalidName', b'ValidValue'),
+            (b'\nInvalidName', b'ValidValue'),
+            (b' InvalidName', b'ValidValue'),
+            (b'\tInvalidName', b'ValidValue'),
+            (b'Invalid:Name', b'ValidValue'),
+            (b':InvalidName', b'ValidValue'),
+            (b'ValidName', b'Invalid\r\nValue'),
+            (b'ValidName', b'Invalid\rValue'),
+            (b'ValidName', b'Invalid\nValue'),
+            (b'ValidName', b'InvalidValue\r\n'),
+            (b'ValidName', b'InvalidValue\r'),
+            (b'ValidName', b'InvalidValue\n'),
+        )
+        for name, value in cases:
+            with self.assertRaisesRegex(ValueError, 'Invalid header'):
+                conn.putheader(name, value)
 
 class BasicTest(TestCase):
     def test_status_lines(self):
