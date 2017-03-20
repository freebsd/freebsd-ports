--- lang/LangSource/SC_TerminalClient.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangSource/SC_TerminalClient.cpp
@@ -626,7 +626,7 @@ void SC_TerminalClient::initInput()
 
 void SC_TerminalClient::startInput()
 {
-	thread thread(std::bind(&SC_TerminalClient::inputThreadFn, this));
+	std::thread thread(std::bind(&SC_TerminalClient::inputThreadFn, this));
 	mInputThread = std::move(thread);
 }
 
