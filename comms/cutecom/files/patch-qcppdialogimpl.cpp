--- qcppdialogimpl.cpp.orig	2009-03-28 12:42:56.000000000 -0500
+++ qcppdialogimpl.cpp	2009-03-28 12:44:32.000000000 -0500
@@ -243,11 +243,10 @@
    bool entryFound=false;
    QStringList devices=settings.readListEntry("/cutecom/AllDevices", &entryFound);
    if (!entryFound)
-      devices<<"/dev/ttyS0"<<"/dev/ttyS1"<<"/dev/ttyS2"<<"/dev/ttyS3";
+      devices<<DEVLIST;
 
    m_deviceCb->insertStringList(devices);
-
-   m_deviceCb->setCurrentText(settings.readEntry("/cutecom/CurrentDevice", "/dev/ttyS0"));
+   m_deviceCb->setCurrentText(settings.readEntry("/cutecom/CurrentDevice", DEFAULT_DEV));
 
    QStringList history=settings.readListEntry("/cutecom/History");
 
@@ -932,9 +931,9 @@
    case 460800:
       _baud=B460800;
       break;
-   case 576000:
-      _baud=B576000;
-      break;
+//   case 576000:
+//      _baud=B576000;
+//      break;
    case 921600:
       _baud=B921600;
       break;
