--- ./trac/notification.py.orig	Sun Mar  4 18:14:39 2007
+++ ./trac/notification.py	Sun Mar  4 21:58:03 2007
@@ -225,6 +225,13 @@
             tmp = name.encode('ascii')
             header = Header(tmp, 'ascii', maxlinelen=maxlength)
         except UnicodeEncodeError:
+	  if self.env.config.get('notification', 'mime_encoding').lower() == 'none':
+	    try:
+		tmp = name.encode('iso-2022-jp')
+		header = Header(tmp, 'iso-2022-jp', maxlinelen=maxlength)
+	    except UnicodeEncodeError:
+		pass
+	  if not header:
             header = Header(name, self._charset, maxlinelen=maxlength)
         if not email:
             return header
@@ -343,12 +350,17 @@
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
+	      try:
+		dummy = unicode(body, 'utf8');
+		body = dummy.encode('iso-2022-jp')
+		self._charset.output_charset = 'iso-2022-jp'
+	      except UnicodeDecodeError:
                 raise TracError, "Ticket contains non-Ascii chars. " \
                                  "Please change encoding setting"
         msg = MIMEText(body, 'plain')
