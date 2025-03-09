--- src/slic3r/Utils/TCPConsole.cpp.orig	2025-02-14 23:42:57 UTC
+++ src/slic3r/Utils/TCPConsole.cpp
@@ -161,7 +161,7 @@ bool TCPConsole::run_queue()
 
         auto endpoints = m_resolver.resolve(m_host_name, m_port_name);
 
-        m_socket.async_connect(endpoints->endpoint(),
+        m_socket.async_connect(endpoints.begin()->endpoint(),
             boost::bind(&TCPConsole::handle_connect, this, boost::placeholders::_1)
         );
 
