--- src/dialogs/kickpimcard.cpp.orig	Sun Aug 15 19:54:43 2004
+++ src/dialogs/kickpimcard.cpp	Sun Aug 15 19:55:32 2004
@@ -309,7 +309,7 @@
   if (prefFound)      m_content[PHONE]->selectContent( i18n("Preferred Number") );
   else if (homeFound) m_content[PHONE]->selectContent( i18n("home phone") );
   else                m_content[PHONE]->selectContent( i18n(phoneMap.begin().key()) );
-};
+}
 
 
 void KickPimCard::setAddressContent()
@@ -352,7 +352,7 @@
   if (type && KABC::Address::Pref)   text+="Pref<br>";
 */
   return text;
-};
+}
 
 void KickPimCard::setBirthdayContent ()
 {
