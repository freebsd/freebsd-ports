--- rig/rigcontrol.cpp.orig	2019-04-19 04:54:51 UTC
+++ rig/rigcontrol.cpp
@@ -377,7 +377,7 @@ void rigControl::activatePTT(bool b)
       if (catParams.pttSerialPort.isEmpty()) return;
       if(serialP==0)
         {
-          serialP=::open(catParams.pttSerialPort.toLatin1().data(),O_RDWR);
+          serialP=::open(catParams.pttSerialPort.toLatin1().data(),O_RDWR|O_NONBLOCK);
           if (serialP<=0)
             {
               QMessageBox::warning(txWidgetPtr,"Serial Port Error",
