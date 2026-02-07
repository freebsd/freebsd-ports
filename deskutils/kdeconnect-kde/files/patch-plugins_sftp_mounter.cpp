--- plugins/sftp/mounter.cpp.orig	2025-12-03 23:06:29 UTC
+++ plugins/sftp/mounter.cpp
@@ -102,7 +102,7 @@ void Mounter::onPacketReceived(const NetworkPacket &np
                       << QStringLiteral("-o") << QStringLiteral("gid=") + QString::number(getgid())
                       << QStringLiteral("-o") << QStringLiteral("reconnect")
                       << QStringLiteral("-o") << QStringLiteral("ServerAliveInterval=30")
-                      << QStringLiteral("-o") << QStringLiteral("password_stdin");
+                      << QStringLiteral("-o") << QStringLiteral("ssh_command=sshpass -p %1 %2").arg(np.get<QString>(QStringLiteral("password")), QStringLiteral("ssh"));
     // clang-format on
 
     m_proc->setProgram(program, arguments);
@@ -111,8 +111,8 @@ void Mounter::onPacketReceived(const NetworkPacket &np
     m_proc->start();
 
     // qCDebug(KDECONNECT_PLUGIN_SFTP) << "Passing password: " << np.get<QString>("password").toLatin1();
-    m_proc->write(np.get<QString>(QStringLiteral("password")).toLatin1());
-    m_proc->write("\n");
+    //m_proc->write(np.get<QString>(QStringLiteral("password")).toLatin1());
+    //m_proc->write("\n");
 }
 
 void Mounter::onStarted()
