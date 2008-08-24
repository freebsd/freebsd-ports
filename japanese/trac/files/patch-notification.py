--- trac/notification.py.orig	2008-08-17 14:28:38.000000000 +0900
+++ trac/notification.py	2008-08-24 18:30:45.000000000 +0900
@@ -248,6 +248,7 @@
     def format_header(self, key, name, email=None):
         from email.Header import Header
         maxlength = MAXHEADERLEN-(len(key)+2)
+        header = None
         # Do not sent ridiculous short headers
         if maxlength < 10:
             raise TracError(_("Header length is too short"))
@@ -255,6 +256,13 @@
             tmp = name.encode('ascii')
             header = Header(tmp, 'ascii', maxlinelen=maxlength)
         except UnicodeEncodeError:
+          if self.env.config.get('notification', 'mime_encoding').lower() == 'none':
+            try:
+              tmp = name.encode('iso-2022-jp')
+              header = Header(tmp, 'iso-2022-jp', maxlinelen=maxlength)
+            except UnicodeEncodeError:
+              pass
+          if not header:
             header = Header(name, self._charset, maxlinelen=maxlength)
         if not email:
             return header
@@ -386,12 +394,17 @@
                 headers['To'] = ', '.join(toaddrs)
         if pcc:
             headers['Cc'] = ', '.join(pcc)
-        headers['Date'] = formatdate()
+        headers['Date'] = formatdate(time.time(), self.config.getbool('notification', 'local_timezone'))
         # sanity check
         if not self._charset.body_encoding:
             try:
                 dummy = body.encode('ascii')
             except UnicodeDecodeError:
+             try:
+              dummy = unicode(body, 'utf8')
+              body = dummy.encode('iso-2022-jp')
+              self._charset.output_charset = 'iso-2022-jp'
+             except UnicodeDecodeError:
                 raise TracError(_("Ticket contains non-ASCII chars. " \
                                   "Please change encoding setting"))
         msg = MIMEText(body, 'plain')
