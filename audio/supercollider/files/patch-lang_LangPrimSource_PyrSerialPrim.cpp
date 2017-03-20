--- lang/LangPrimSource/PyrSerialPrim.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangPrimSource/PyrSerialPrim.cpp
@@ -145,7 +145,7 @@ class SerialPort (private)
 
 	// rx thread
 	std::atomic<bool>	m_running;
-	thread				m_thread;
+	std::thread				m_thread;
 };
 
 PyrSymbol* SerialPort::s_dataAvailable = 0;
@@ -340,7 +340,7 @@ SerialPort::SerialPort(PyrObject* obj, const char* ser
 	m_rxErrors[0] = m_rxErrors[1] = 0;
 
 	try {
-		thread thread(std::bind(&SerialPort::threadLoop, this));
+		std::thread thread(std::bind(&SerialPort::threadLoop, this));
 		m_thread = std::move(thread);
 	} catch(std::exception & e) {
 		close(m_fd);
