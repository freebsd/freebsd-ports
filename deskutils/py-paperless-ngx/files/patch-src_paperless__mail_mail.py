--- src/paperless_mail/mail.py.orig	2025-06-19 19:07:49 UTC
+++ src/paperless_mail/mail.py
@@ -29,7 +29,7 @@ from imap_tools import MailBoxUnencrypted
 from imap_tools import MailMessage
 from imap_tools import MailMessageFlags
 from imap_tools import errors
-from imap_tools.mailbox import MailBoxTls
+from imap_tools.mailbox import MailBoxStartTls
 from imap_tools.query import LogicOperator
 
 from documents.data_models import ConsumableDocument
@@ -419,7 +419,7 @@ def get_mailbox(server, port, security) -> MailBox:
     if security == MailAccount.ImapSecurity.NONE:
         mailbox = MailBoxUnencrypted(server, port)
     elif security == MailAccount.ImapSecurity.STARTTLS:
-        mailbox = MailBoxTls(server, port, ssl_context=ssl_context)
+        mailbox = MailBoxStartTls(server, port, ssl_context=ssl_context)
     elif security == MailAccount.ImapSecurity.SSL:
         mailbox = MailBox(server, port, ssl_context=ssl_context)
     else:
