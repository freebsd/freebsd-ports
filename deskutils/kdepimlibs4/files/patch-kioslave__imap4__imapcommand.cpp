commit ddc273ca863aacc65742bf6193826809a2d3265e
Author: Allen Winter <winter@kde.org>
Date:   Sat Dec 17 12:38:49 2011 -0500

    In clientAppend(), be careful how the arguments for the APPEND command
    are constructed so as not to break things.
    
    Found by Luke Dashjr <luke-jr+git@utopios.org>
    with help from Andreas. Thanks guys.
    Please test this.
    
    BUG: 289084
    FIXED-IN: 4.8.0

diff --git a/kioslave/imap4/imapcommand.cpp b/kioslave/imap4/imapcommand.cpp
index 43daccd..88d95df 100644
--- ./kioslave/imap4/imapcommand.cpp
+++ ./kioslave/imap4/imapcommand.cpp
@@ -231,7 +231,12 @@ CommandPtr
 imapCommand::clientAppend (const QString & box, const QString & flags,
                            ulong size)
 {
-  QString tmp = QString(flags.isEmpty() ? QString("") : QString(('(' + flags + ") ")) + '{' + QString::number(size) + '}'); 
+  QString tmp;
+  if ( !flags.isEmpty() ) {
+    tmp = '(' + flags + ") ";
+  }
+  tmp += '{' + QString::number( size ) + '}';
+
   return CommandPtr( new imapCommand ("APPEND",
                           "\"" + KIMAP::encodeImapFolderName (box) + "\" " + tmp));
 }
