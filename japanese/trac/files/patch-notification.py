--- trac/notification.py.orig	2009-09-16 14:26:41.787493029 +0900
+++ trac/notification.py	2009-09-16 14:25:56.397348835 +0900
@@ -243,6 +243,7 @@
     def format_header(self, key, name, email=None):
         from email.Header import Header
         maxlength = MAXHEADERLEN-(len(key)+2)
+        header = None
         # Do not sent ridiculous short headers
         if maxlength < 10:
             raise TracError(_("Header length is too short"))
@@ -250,7 +251,14 @@
             tmp = name.encode('ascii')
             header = Header(tmp, 'ascii', maxlinelen=maxlength)
         except UnicodeEncodeError:
-            header = Header(name, self._charset, maxlinelen=maxlength)
+            if self.env.config.get('notification', 'mime_encoding').lower() == 'none':
+                try:
+                    tmp = name.encode('iso-2022-jp')
+                    header = Header(tmp, 'iso-2022-jp', maxlinelen=maxlength)
+                except UnicodeEncodeError:
+                    pass
+            if not header:
+                header = Header(name, self._charset, maxlinelen=maxlength)
         if not email:
             return header
         else:
@@ -383,6 +391,35 @@
         if pcc:
             headers['Cc'] = ', '.join(pcc)
         headers['Date'] = formatdate()
+        # Use specified timezone in Date: header.
+        tz = self.config.get('trac', 'default_timezone')
+        if tz:
+            import os
+            preserve_tz = 0
+            old_tz = ''
+            if os.environ.has_key('TZ'):
+                preserve_tz = 1
+                old_tz = os.environ['TZ']
+            os.environ['TZ'] = tz
+            time.tzset()
+            headers['Date'] = formatdate(time.time(), True)
+            if preserve_tz:
+                os.environ['TZ'] = old_tz
+            else:
+                del os.environ['TZ']
+            time.tzset()
+        if not self._charset.body_encoding:
+            try:
+                dummy = body.encode('ascii')
+            except UnicodeDecodeError:
+                try:
+                    dummy = unicode(body, 'utf8')
+                    body = dummy.encode('iso-2022-jp')
+                    self._charset.output_charset = 'iso-2022-jp'
+                except UnicodeEncodeError:
+                    pass
+                except UnicodeDecodeError:
+                    pass
         msg = MIMEText(body, 'plain')
         # Message class computes the wrong type from MIMEText constructor,
         # which does not take a Charset object as initializer. Reset the
