--- libkpimexchange/core/exchangeaccount.cpp.old	Mon Jul 21 16:59:08 2003
+++ libkpimexchange/core/exchangeaccount.cpp	Mon Jul 21 16:59:29 2003
@@ -255,7 +255,7 @@
   return result;
 }
   
-static QString ExchangeAccount::tryMailbox( const QString& _url, const QString& user, const QString& password ) {
+QString ExchangeAccount::tryMailbox( const QString& _url, const QString& user, const QString& password ) {
   KURL url = KURL( _url );
   url.setUser( user );
   url.setPass( password );
