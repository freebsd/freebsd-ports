--- kbear/plugins/transferqueue/transferqueueconfigwidget.cpp.orig	Sun Jun  6 03:12:32 2004
+++ kbear/plugins/transferqueue/transferqueueconfigwidget.cpp	Sun Jun  6 03:13:35 2004
@@ -110,7 +110,7 @@
 		m_config->sync();
 	}
 	m_sysShutdownCheckBox->setChecked( m_config->readBoolEntry( QString::fromLatin1("SysShutdownWhenDone"), false ) );
-	m_queueCheckBox->setChecked( m_config->readBoolEntry( QString::fromLatin1("QueueTransfers"), false ) );
+	m_queueCheckBox->setChecked( m_config->readBoolEntry( QString::fromLatin1("QueueTransfers"), true ) );
 	m_countSpinBox->setValue( m_config->readUnsignedNumEntry( QString::fromLatin1("NumberOfTransfers"), 1 ) );
 	m_disconnectCommandLineEdit->setText( m_config->readEntry( QString::fromLatin1("DisconnectCommand"), QString::fromLatin1("kppp -k") ) );
 
