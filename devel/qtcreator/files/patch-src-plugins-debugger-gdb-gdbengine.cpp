--- src/plugins/debugger/gdb/gdbengine.cpp.orig	2009-06-02 22:07:51.000000000 +0300
+++ src/plugins/debugger/gdb/gdbengine.cpp	2009-06-03 19:37:47.000000000 +0300
@@ -684,7 +684,7 @@
     if (cmd.flags & EmbedToken)
         cmd.command = cmd.command.arg(currentToken());
 
-    m_gdbProc.write(cmd.command.toLatin1() + "\r\n");
+    m_gdbProc.write(cmd.command.toLatin1() + "\n");
     //emit gdbInputAvailable(QString(), "         " +  currentTime());
     //emit gdbInputAvailable(QString(), "[" + currentTime() + "]    " + cmd.command);
     emit gdbInputAvailable(QString(), cmd.command);
@@ -752,7 +752,7 @@
         return;
     }
 
-    m_gdbProc.write(command.toLocal8Bit() + "\r\n");
+    m_gdbProc.write(command.toLocal8Bit() + "\n");
 }
 
 void GdbEngine::handleTargetCore(const GdbResultRecord &, const QVariant &)
