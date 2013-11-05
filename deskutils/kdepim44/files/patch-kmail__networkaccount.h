libc++ build fix.
--- kmail/networkaccount.h
+++ kmail/networkaccount.h
@@ -33,7 +33,6 @@
 
 #include <QString>
 
-class AccountManager;
 class KConfig/*Base*/;
 class KUrl;
 namespace KIO {
@@ -42,6 +41,8 @@ namespace KIO {
 
 namespace KMail {
 
+  class AccountManager;
+
   class NetworkAccount : public KMAccount {
     Q_OBJECT
   protected:
