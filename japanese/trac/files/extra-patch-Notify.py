--- trac/Notify.py.orig2	Tue Aug 22 19:47:42 2006
+++ trac/Notify.py	Tue Aug 22 19:48:00 2006
@@ -139,7 +139,7 @@
         msg['Sender'] = self.from_email
         msg['Reply-To'] = self.replyto_email
         msg['To'] = rcpt
-        msg['Date'] = formatdate()
+        msg['Date'] = formatdate(time.time(), self.config.getbool('notification', 'local_timezone'))
         for hdr in mime_headers.keys():
             msg[hdr] = mime_headers[hdr]
         self.env.log.debug("Sending SMTP notification to %s on port %d"
