--- src/HaplohSeq.cpp.orig	2019-09-01 14:58:30 UTC
+++ src/HaplohSeq.cpp
@@ -202,7 +202,7 @@ void HaplohSeq::runBafHaplohseq(	std::string& obsType,
 
 		// Spawn worker threads
 		for (std::size_t t = 0; t < numThreads; t++) {
-			threadPool.create_thread(boost::bind((unsigned long int (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
+			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
 		}
 
 		std::map<std::string, boost::shared_ptr<Hmm> > chrHmms;
@@ -420,7 +420,7 @@ void HaplohSeq::runVcfHaplohseq(	std::string& obsType,
 
 		// Spawn worker threads
 		for (std::size_t t = 0; t < numThreads; t++) {
-			threadPool.create_thread(boost::bind((unsigned long int (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
+			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
 		}
 
 		std::map<std::string, boost::shared_ptr<Hmm> > chrHmms;
