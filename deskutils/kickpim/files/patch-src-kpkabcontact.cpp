--- src/kpkabcontact.cpp.orig	Sun Aug 15 20:07:22 2004
+++ src/kpkabcontact.cpp	Sun Aug 15 20:09:00 2004
@@ -240,7 +240,7 @@
   {
     m_addr->insertEmail(emailAddr, preferred);
   }
-};
+}
 
 
 
@@ -255,7 +255,7 @@
     ++itor;
   }
 
-};
+}
 
 void KPKabContact::addPhoneNumber(QString number, QString key)
 {
@@ -270,20 +270,20 @@
       }
     }
   }
-};
+}
 
 void KPKabContact::setBirthday    ( QDate date )
 {
   if (!m_addr) return;
   m_addr->setBirthday(date);
-};
+}
 
 void KPKabContact::setAnniversary ( QDate date )
 {
   if (!m_addr) return;
   QString dateStr = date.toString( Qt::ISODate );
   m_addr->insertCustom( "KADDRESSBOOK", "X-Anniversary" , dateStr );
-};
+}
 
 
 bool KPKabContact::edit()
@@ -322,4 +322,4 @@
     }
   }
   KABC::StdAddressBook::save();
-};
+}
