--- plugins/sftp/mounter.cpp.orig	2018-11-06 14:32:08.000000000 +0100
+++ plugins/sftp/mounter.cpp	2019-01-29 18:43:47.324002000 +0100
@@ -139,7 +139,7 @@
         << QStringLiteral("-o") << QStringLiteral("gid=") + QString::number(getgid())
         << QStringLiteral("-o") << QStringLiteral("reconnect")
         << QStringLiteral("-o") << QStringLiteral("ServerAliveInterval=30")
-        << QStringLiteral("-o") << QStringLiteral("password_stdin")
+        << QStringLiteral("-o") << QStringLiteral("ssh_command=sshpass -p %1 %2").arg(np.get<QString>(QStringLiteral("password")), QStringLiteral("ssh"))
         ;
 
     m_proc->setProgram(program, arguments);
@@ -148,8 +148,8 @@
     m_proc->start();
 
     //qCDebug(KDECONNECT_PLUGIN_SFTP) << "Passing password: " << np.get<QString>("password").toLatin1();
-    m_proc->write(np.get<QString>(QStringLiteral("password")).toLatin1());
-    m_proc->write("\n");
+    //m_proc->write(np.get<QString>(QStringLiteral("password")).toLatin1());
+    //  m_proc->write("\n");
 
 }
 
