--- konversation/src/dccdetaildialog.cpp.orig	Tue Jun  7 10:52:46 2005
+++ konversation/src/dccdetaildialog.cpp	Tue Jun  7 10:53:22 2005
@@ -238,7 +238,7 @@
     QString self;
     if ( !m_item->m_ownIp.isEmpty() || !m_item->m_ownPort.isEmpty() )
       m_self->setText( QString( "%1:%2" )
-                      .arg( !m_item->m_ownIp.isEmpty() ? m_item->m_ownIp : "* " )
+                      .arg( !m_item->m_ownIp.isEmpty() ? m_item->m_ownIp : QString("* ") )
                       .arg( !m_item->m_ownPort.isEmpty() ? m_item->m_ownPort : i18n("unknown") )
                      );
     else
