libc++ build fix.
--- kmail/imapaccountbase.h
+++ kmail/imapaccountbase.h
@@ -37,7 +37,6 @@
 #include <QByteArray>
 #include "progressmanager.h"
 
-class AccountManager;
 class KMFolder;
 class KConfigGroup;
 class KMMessagePart;
@@ -55,6 +54,8 @@ namespace KPIM {
 }
 
 namespace KMail {
+  class AccountManager;
+
   struct ACLListEntry;
   class QuotaInfo;
   typedef QVector<KMail::ACLListEntry> ACLList;
