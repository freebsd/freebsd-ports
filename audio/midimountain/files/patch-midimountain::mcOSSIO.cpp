--- midimountain/mcOSSIO.cpp.orig	Tue Oct 23 23:19:14 2001
+++ midimountain/mcOSSIO.cpp	Mon Jul  2 14:09:01 2007
@@ -1,17 +1,18 @@
 //=============================================================================
 // implementation class midi IO
 //=============================================================================
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <string.h>
 #include <iostream.h>
 #include <mcOSSIO.h>
+#include <iomanip>
 
 
 // define static variables:
-const char* TMidiOSSIO::sequencer       = "/dev/music";
+const char* TMidiOSSIO::sequencer       = "/dev/music0";
 int    TMidiOSSIO::class_count          =  0;
 uchar  TMidiOSSIO::midi_write_packet[4] = {SEQ_MIDIPUTC, 0, 0, 0};
 uchar  TMidiOSSIO::midi_read_packet[4];
@@ -464,7 +465,7 @@
 					break;
 
 				default:
-					cout << "unknown EV_TIMING" << hex << buf[i+1];
+					cout << "unknown EV_TIMING" << std::hex << buf[i+1];
 					break;
 				}
 				i += 8;
