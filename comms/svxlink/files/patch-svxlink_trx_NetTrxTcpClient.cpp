--- svxlink/trx/NetTrxTcpClient.cpp.orig	2014-04-09 23:51:30.000000000 -0700
+++ svxlink/trx/NetTrxTcpClient.cpp	2014-04-09 23:52:13.000000000 -0700
@@ -328,8 +328,8 @@
       {
         MsgProtoVer *ver_msg = reinterpret_cast<MsgProtoVer *>(msg);
         if ((msg->size() != sizeof(MsgProtoVer)) ||
-            (ver_msg->major() != MsgProtoVer::MAJOR) ||
-            (ver_msg->minor() != MsgProtoVer::MINOR))
+            (ver_msg->FBSD_major() != MsgProtoVer::MAJOR) ||
+            (ver_msg->FBSD_minor() != MsgProtoVer::MINOR))
         {
           cerr << "*** ERROR: Incompatible protocol version. Disconnecting from "
                << remoteHost().toString() << ":" << remotePort() << "...\n";
@@ -337,8 +337,8 @@
           return;
         }
         cout << remoteHost().toString() << ":" << remotePort()
-             << ": RemoteTrx protocol version " << ver_msg->major() << "."
-             << ver_msg->minor() << endl;
+             << ": RemoteTrx protocol version " << ver_msg->FBSD_major() << "."
+             << ver_msg->FBSD_minor() << endl;
         state = STATE_AUTH_WAIT;
       }
       else
