--- qcppdialogimpl.cpp.orig	Thu Jul 29 22:24:43 2004
+++ qcppdialogimpl.cpp	Fri Jul 30 10:22:04 2004
@@ -167,11 +167,19 @@
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
    m_oldCmdsLb->insertStringList(history);
@@ -659,15 +667,21 @@
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
