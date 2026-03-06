--- src/libslic3r/GCodeSender.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/libslic3r/GCodeSender.cpp
@@ -8,7 +8,7 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <boost/lexical_cast.hpp>
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <termios.h>
 #endif
 #ifdef __APPLE__
@@ -107,7 +107,7 @@ GCodeSender::connect(std::string devname, unsigned int
     this->io.post(boost::bind(&GCodeSender::do_read, this));
     
     // start reading in the background thread
-    boost::thread t(boost::bind(&boost::asio::io_service::run, &this->io));
+    boost::thread t(boost::bind(&boost::asio::io_context::run, &this->io));
     this->background_thread.swap(t);
     
     // always send a M105 to check for connection because firmware might be silent on connect
@@ -146,7 +146,7 @@ GCodeSender::set_baud_rate(unsigned int baud_rate)
         if (ioctl(handle, TCSETS2, &ios))
             printf("Error in TCSETS2: %s\n", strerror(errno));
 		
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 		struct termios ios;
 		::tcgetattr(handle, &ios);
 		::cfsetspeed(&ios, baud_rate);
