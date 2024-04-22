--- plugins/sftp/mounter.cpp.orig	2024-02-10 04:18:49 UTC
+++ plugins/sftp/mounter.cpp
@@ -130,7 +130,7 @@ void Mounter::onPackageReceived(const NetworkPacket &n
                       << QStringLiteral("-o") << QStringLiteral("PubkeyAcceptedKeyTypes=+ssh-rsa") // https://bugs.kde.org/show_bug.cgi?id=443155
                       << QStringLiteral("-o") << QStringLiteral("uid=") + QString::number(getuid()) << QStringLiteral("-o")
                       << QStringLiteral("gid=") + QString::number(getgid()) << QStringLiteral("-o") << QStringLiteral("reconnect") << QStringLiteral("-o")
-                      << QStringLiteral("ServerAliveInterval=30") << QStringLiteral("-o") << QStringLiteral("password_stdin");
+                      << QStringLiteral("ServerAliveInterval=30") << QStringLiteral("-o") << QStringLiteral("ssh_command=sshpass -p %1 %2").arg(np.get<QString>(QStringLiteral("password")), QStringLiteral("ssh"));
 
     m_proc->setProgram(program, arguments);
 
@@ -138,8 +138,8 @@ void Mounter::onPackageReceived(const NetworkPacket &n
     m_proc->start();
 
     // qCDebug(KDECONNECT_PLUGIN_SFTP) << "Passing password: " << np.get<QString>("password").toLatin1();
-    m_proc->write(np.get<QString>(QStringLiteral("password")).toLatin1());
-    m_proc->write("\n");
+    //m_proc->write(np.get<QString>(QStringLiteral("password")).toLatin1());
+    //m_proc->write("\n");
 }
 
 void Mounter::onStarted()
