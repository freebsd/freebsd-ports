--- qcppdialogimpl.cpp.orig	Tue Jul 13 21:30:51 2004
+++ qcppdialogimpl.cpp	Thu Jul 15 01:45:55 2004
@@ -44,6 +44,9 @@
 #include <ctype.h>
 #include <sys/ioctl.h>
 #include <sys/termios.h>
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
 #include <fcntl.h>
 
 QCPPDialogImpl::QCPPDialogImpl(QWidget* parent)
@@ -147,11 +150,19 @@
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
 }
 
 void QCPPDialogImpl::showAboutMsg()
@@ -610,15 +621,21 @@
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
