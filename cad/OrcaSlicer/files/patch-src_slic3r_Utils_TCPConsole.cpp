--- src/slic3r/Utils/TCPConsole.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/Utils/TCPConsole.cpp
@@ -170,7 +170,7 @@ bool TCPConsole::run_queue()
 
         auto endpoints = m_resolver.resolve(m_host_name, m_port_name);
 
-        m_socket.async_connect(endpoints->endpoint(),
+        m_socket.async_connect(endpoints.begin()->endpoint(),
             boost::bind(&TCPConsole::handle_connect, this, boost::placeholders::_1)
         );
 
