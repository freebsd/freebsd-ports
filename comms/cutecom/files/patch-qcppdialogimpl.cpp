--- qcppdialogimpl.cpp.orig	Wed Oct 13 23:28:30 2004
+++ qcppdialogimpl.cpp	Fri Oct 15 19:04:08 2004
@@ -190,11 +190,19 @@
    bool entryFound=false;
    QStringList devices=settings.readListEntry("/cutecom/AllDevices", &entryFound);
    if (!entryFound)
+#ifdef __FreeBSD__
+      devices<<"/dev/cuaa0"<<"/dev/cuaa1"<<"/dev/cuaa2"<<"/dev/cuaa3";
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
 
@@ -295,7 +303,7 @@
       m_sz->addArgument("sh");
       m_sz->addArgument("-c");
 //      QString tmp=QString("sx -vv \"")+filename+"\" < "+m_deviceCb->currentText()+" > "+m_deviceCb->currentText();
-      QString tmp=QString("sz ");
+      QString tmp=QString("lsz ");
       if (m_protoPb->currentText()=="XModem")
          tmp+="--xmodem ";
       else if (m_protoPb->currentText()=="YModem")
@@ -414,7 +422,7 @@
 
 void QCPPDialogImpl::sendDone()
 {
-   cerr<<"sx exited"<<endl;
+   cerr<<"lsx exited"<<endl;
 }
 
 bool QCPPDialogImpl::eventFilter(QObject* watched, QEvent *e)
@@ -773,15 +781,21 @@
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
