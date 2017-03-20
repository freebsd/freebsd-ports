--- lang/LangSource/SC_TerminalClient.h.orig	2017-03-20 15:18:39 UTC
+++ lang/LangSource/SC_TerminalClient.h
@@ -166,7 +166,7 @@ class SCLANG_DLLEXPORT SC_TerminalClient : public SC_L
 
 	// input io service
 	boost::asio::io_service mInputService;
-	thread mInputThread;
+	std::thread mInputThread;
 	void inputThreadFn();
 
 	static const size_t inputBufferSize = 256;
