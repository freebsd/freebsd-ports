--- trac/Notify.py.orig	Thu Dec 15 23:47:03 2005
+++ trac/Notify.py	Thu Dec 15 23:48:21 2005
@@ -124,15 +124,14 @@
         from email.Header import Header
         from email.Utils import formatdate
         body = self.hdf.render(self.template_name)
-        msg = MIMEMultipart()
-        msg.attach(MIMEText(body, 'plain', 'utf-8'))
-        msg.epilogue = ''
+        body = unicode(body, 'utf-8').encode('japanese.c.iso-2022-jp')
+        msg = MIMEText(body, 'plain', 'iso-2022-jp')
         msg['X-Mailer'] = 'Trac %s, by Edgewall Software' % __version__
         msg['X-Trac-Version'] =  __version__
         projname = self.config.get('project','name')
         msg['X-Trac-Project'] =  projname
         msg['X-URL'] =  self.config.get('project','url')
-        msg['Subject'] = Header(self.subject, 'utf-8')
+        msg['Subject'] = Header(unicode(self.subject, 'utf-8').encode('japanese.c.iso-2022-jp'), 'iso-2022-jp')
         msg['From'] = '%s <%s>' % (projname, self.from_email)
         msg['Sender'] = self.from_email
         msg['Reply-To'] = self.replyto_email
