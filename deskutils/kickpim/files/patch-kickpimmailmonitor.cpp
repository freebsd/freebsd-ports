--- src/mailing/kickpimmailmonitor.cpp.orig	Sun Nov 23 14:12:12 2003
+++ src/mailing/kickpimmailmonitor.cpp	Mon Dec 29 16:07:13 2003
@@ -226,7 +226,7 @@
         case NewMail:
         case NoMail:
         case OldMail:
-            text = (m_curCount<0 ? "-" : QString::number( m_curCount ) );
+            text = (m_curCount<0 ? QString("-") : QString::number( m_curCount ) );
             break;
         case NoConn:
             text="...";
