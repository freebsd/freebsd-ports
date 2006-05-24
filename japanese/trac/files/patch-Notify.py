--- trac/Notify.py.orig	Thu Feb 16 10:47:21 2006
+++ trac/Notify.py	Wed May 24 16:12:07 2006
@@ -23,6 +23,7 @@
 import md5
 import time
 import smtplib
+import string
 
 
 class Notify:
@@ -123,15 +124,17 @@
         from email.Header import Header
         from email.Utils import formatdate
         body = self.hdf.render(self.template_name)
-        msg = MIMEMultipart()
-        msg.attach(MIMEText(body, 'plain', 'utf-8'))
-        msg.epilogue = ''
+	body_esc = string.replace(unicode(body, 'utf-8'), u'\uff5e', u'\u301c')
+	body = body_esc.encode('japanese.c.iso-2022-jp')
+        msg = MIMEText(body, 'plain', 'iso-2022-jp')
         msg['X-Mailer'] = 'Trac %s, by Edgewall Software' % __version__
         msg['X-Trac-Version'] =  __version__
         projname = self.config.get('project','name')
         msg['X-Trac-Project'] =  projname
         msg['X-URL'] =  self.config.get('project','url')
-        msg['Subject'] = Header(self.subject, 'utf-8')
+	subj = unicode(self.subject, 'utf-8')
+	subj_esc = string.replace(subj, u'\uff5e', u'\u301c')
+	msg['Subject'] = Header(subj_esc.encode('japanese.c.iso-2022-jp'), 'iso-2022-jp')
         msg['From'] = '%s <%s>' % (projname, self.from_email)
         msg['Sender'] = self.from_email
         msg['Reply-To'] = self.replyto_email
