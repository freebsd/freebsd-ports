--- trac/notification.py.orig	Sat Dec  9 19:06:15 2006
+++ trac/notification.py	Tue Mar  6 16:31:37 2007
@@ -218,6 +218,7 @@
     def format_header(self, key, name, email=None):
         from email.Header import Header
         maxlength = MAXHEADERLEN-(len(key)+2)
+	header = None
         # Do not sent ridiculous short headers
         if maxlength < 10:
             raise TracError, "Header length is too short"
@@ -225,6 +226,13 @@
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
@@ -343,12 +351,17 @@
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
