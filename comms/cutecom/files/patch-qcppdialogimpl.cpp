--- qcppdialogimpl.cpp.orig	Thu Jun  9 21:43:44 2005
+++ qcppdialogimpl.cpp	Thu Jun  9 23:26:47 2005
@@ -217,11 +217,23 @@
    bool entryFound=false;
    QStringList devices=settings.readListEntry("/cutecom/AllDevices", &entryFound);
    if (!entryFound)
+#ifdef __FreeBSD__
+#if __FreeBSD_version < 600000
+      devices<<"/dev/cuaa0"<<"/dev/cuaa1"<<"/dev/cuaa2"<<"/dev/cuaa3";
+#else
+      devices<<"/dev/cuad0"<<"/dev/cuad1"<<"/dev/cuad2"<<"/dev/cuad3";
+#endif
+#else
       devices<<"/dev/ttyS0"<<"/dev/ttyS1"<<"/dev/ttyS2"<<"/dev/ttyS3";
+#endif
 
    m_deviceCb->insertStringList(devices);
 
+#ifdef __FreeBSD__
+   m_deviceCb->setCurrentText(settings.readEntry("/cutecom/CurrentDevice", "/dev/cuaa0"));
+#else
    m_deviceCb->setCurrentText(settings.readEntry("/cutecom/CurrentDevice", "/dev/ttyS0"));
+#endif
 
    QStringList history=settings.readListEntry("/cutecom/History");
 
@@ -326,7 +338,7 @@
       m_sz->addArgument("sh");
       m_sz->addArgument("-c");
 //      QString tmp=QString("sx -vv \"")+filename+"\" < "+m_deviceCb->currentText()+" > "+m_deviceCb->currentText();
-      QString tmp=QString("sz ");
+      QString tmp=QString("lsz ");
       if (m_protoPb->currentText()=="XModem")
          tmp+="--xmodem ";
       else if (m_protoPb->currentText()=="YModem")
@@ -445,7 +457,7 @@
 
 void QCPPDialogImpl::sendDone()
 {
-   cerr<<"sx exited"<<endl;
+   cerr<<"lsx exited"<<endl;
 }
 
 bool QCPPDialogImpl::eventFilter(QObject* watched, QEvent *e)
@@ -885,15 +897,21 @@
    case 230400:
       _baud=B230400;
       break;
+#if !defined(__FreeBSD__) || (_FreeBSD_version > 500000)
    case 460800:
       _baud=B460800;
       break;
+#endif
+#ifndef __FreeBSD__
    case 576000:
       _baud=B576000;
       break;
+#endif
+#if !defined(__FreeBSD__) || (_FreeBSD_version >= 500000)
    case 921600:
       _baud=B921600;
       break;
+#endif
 //   case 128000:
 //      _baud=B128000;
 //      break;
