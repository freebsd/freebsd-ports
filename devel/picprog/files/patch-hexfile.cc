--- hexfile.cc.orig	Tue Nov 19 12:33:41 2002
+++ hexfile.cc	Tue Nov 19 12:38:17 2002
@@ -28,8 +28,8 @@
 
 */
 
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include <sysexits.h>
 #include <string.h>
 #include <ctype.h>
@@ -50,7 +50,7 @@
 
 int hexfile::load (const char *name)
 {
-  ifstream f(name);
+  std::ifstream f(name);
   char buf [128];
   int line = 0;
   enum formats format = unknown;
@@ -59,14 +59,14 @@
 
   if (!f) {
     e = errno;
-    cerr << name << ":unable to load hexfile:" << strerror (e) << endl;
+    std::cerr << name << ":unable to load hexfile:" << strerror (e) << std::endl;
     return EX_NOINPUT;
   }
   while (f.get (buf, sizeof (buf))) {
     line++;
     char c;
     if (f.get (c) && '\n' != c) {
-      cerr << name << ':' << line << ":long input line\n";
+      std::cerr << name << ':' << line << ":long input line\n";
       return EX_DATAERR;
     }
     int len = strlen (buf);
@@ -85,7 +85,7 @@
 
     if (i || ':' != buf [0] || 3 != (len & 3) || len < 15
 	|| '0' != buf [7] || '0' != buf [8]) {
-      cerr << name << ':' << line << ":invalid input line\n";
+      std::cerr << name << ':' << line << ":invalid input line\n";
       return EX_DATAERR;
     }
     check = strtol (buf + len - 2, 0, 16);
@@ -99,15 +99,15 @@
       else if (words * 2 + 11 == len)
 	format = ihx8m;
       else {
-	cerr << name << ':' << line <<
+	std::cerr << name << ':' << line <<
 	  ":unknown input format, only ihx8m and ihx16 accepted\n";
 	return EX_DATAERR;
       }
     }
     if (words * (ihx16 == format ? 4 : 2) + 11 != len) {
-      cerr << name << ':' << line << ":line length mismatch:"
+      std::cerr << name << ':' << line << ":line length mismatch:"
 	   << (ihx16 == format ? "ihx16 " : "ihx8m ")
-	   << words * (ihx16 == format ? 4 : 2) + 11 << " != " << len << endl;
+	   << words * (ihx16 == format ? 4 : 2) + 11 << " != " << len << std::endl;
       return EX_DATAERR;
     }
     sum = words + addr + (addr >> 8);
@@ -120,8 +120,8 @@
 	  || (addr >= 0x2000 && addr+words <= 0x2004)
 	  || (addr == 0x2007 && words == 1)
 	  || (addr >= 0x2100 && addr+words <= 0x2140))) {
-      cerr << name << ':' << line << ":invalid address " << hex
-	   << setw(4) << setfill('0') << addr << dec
+      std::cerr << name << ':' << line << ":invalid address " << std::hex
+	   << std::setw(4) << std::setfill('0') << addr << std::dec
 	   << ", possibly not a pic16c84 hex file?\n";
       return EX_DATAERR;
     }
@@ -135,20 +135,20 @@
       pgm [addr + words] = word;
     }
     if (sum + check & 0xff) {
-      cerr << name << ':' << line << ":checksum mismatch\n";
+      std::cerr << name << ':' << line << ":checksum mismatch\n";
       return EX_DATAERR;
     }
   }
   e = errno;
   if (!f.eof ()) {
-    cerr << name << ':' << line << ':' << strerror (e) << ":\n";
+    std::cerr << name << ':' << line << ':' << strerror (e) << ":\n";
     return EX_IOERR;
   }
-  cerr << name << ':' << line << ":warning:unexpected eof\n";
+  std::cerr << name << ':' << line << ":warning:unexpected eof\n";
   return EX_OK;
 }
 
-void hexfile::save_line (ofstream& f, int begin, int len, enum hexfile::formats format) const
+void hexfile::save_line (std::ofstream& f, int begin, int len, enum hexfile::formats format) const
 {
   int p_begin, p_len, sum, i;
 
@@ -160,21 +160,21 @@
     p_len = len;
   }
 
-  f << ':' << setw (2) << p_len << setw (4) << p_begin << "00";
+  f << ':' << std::setw (2) << p_len << std::setw (4) << p_begin << "00";
 
   sum = p_len + p_begin + (p_begin >> 8);
   for (i = begin; i < begin + len; i++) {
     int word = pgm [i];
     if (ihx8m == format)
       word = (word & 0xff) << 8 | (word & 0xff00) >> 8;
-    f << setw (4) << word;
+    f << std::setw (4) << word;
     sum += word + (word >> 8);
   }
 
-  f << setw (2) << (-sum & 0xff) << endl;
+  f << std::setw (2) << (-sum & 0xff) << std::endl;
 }
 
-void hexfile::save_region (ofstream& f, int addr, int end, enum hexfile::formats format, bool skip_ones) const
+void hexfile::save_region (std::ofstream& f, int addr, int end, enum hexfile::formats format, bool skip_ones) const
 {
   int len;
 
@@ -201,15 +201,15 @@
 
 int hexfile::save (const char *name, enum hexfile::formats format, bool skip_ones) const
 {
-  ofstream f (name);
+  std::ofstream f (name);
   int e;
 
   if (!f) {
     e = errno;
-    cerr << name << ":unable to open save file:" << strerror (e) << endl;
+    std::cerr << name << ":unable to open save file:" << strerror (e) << std::endl;
     return EX_IOERR;
   }
-  f << hex << setfill ('0') << setiosflags (ios::uppercase);
+  f << std::hex << std::setfill ('0') << setiosflags (std::ios::uppercase);
 
   save_region (f, 0, 0x400, format, skip_ones);
   save_region (f, 0x2000, 0x2004, format, skip_ones);
@@ -236,24 +236,24 @@
       && (retval = pic.command (data ? picport::data_from_data
 				: picport::data_from_prog)) != pgm [addr]) {
     if (-1 == retval) {
-      cerr << pic.port() << ':' << hex << setfill ('0') << setw (4) << addr
-	   << dec << ":unable to read pic while programming\n";
+      std::cerr << pic.port() << ':' << std::hex << std::setfill ('0') << std::setw (4) << addr
+	   << std::dec << ":unable to read pic while programming\n";
       return EX_IOERR;
     }
     pic.command (data ? picport::data_for_data : picport::data_for_prog,
 		 pgm [addr]);
     pic.command (picport::beg_prog);
 
-    cout << hex << setfill ('0') << setw (4) << addr << ' '
-	 << setw (4) << pic.address () << ' '
-	 << setw (4) << pgm [addr] << dec << endl;
+    std::cout << std::hex << std::setfill ('0') << std::setw (4) << addr << ' '
+	 << std::setw (4) << pic.address () << ' '
+	 << std::setw (4) << pgm [addr] << std::dec << std::endl;
     
     // verify, but do not verify fuses if Code Protect bit is cleared!
 
     if ((pic.address () != 0x2007 || pgm [addr] & 0x10)
 	&& pgm [addr] != pic.command (data ? picport::data_from_data
 				   : picport::data_from_prog)) {
-      cerr << pic.port() << ':' << hex << setw (4) << setfill ('0') << addr << dec
+      std::cerr << pic.port() << ':' << std::hex << std::setw (4) << std::setfill ('0') << addr << std::dec
 	   << ":unable to verify pic while programming.\n"
 	"Is code protection enabled?  "
 	"Use --erase option to disable code protection.\n";
@@ -280,21 +280,21 @@
     if (reset) {
       pic.reset_code_protection ();
       pic.reset ();
-      cout << "Removed code protection.\n";
+      std::cout << "Removed code protection.\n";
     }
 
-    cout << "Burning program eeprom,\n";
+    std::cout << "Burning program eeprom,\n";
     while (pic.address () < 0x400) {
       if (EX_OK != (retval = program_location (pic, pic.address (), false)))
 	return retval;
       pic.command (picport::inc_addr);
       if (got_signal) {
-	cerr << "Exiting.\n";
+	std::cerr << "Exiting.\n";
 	return EX_UNAVAILABLE;
       }
     }
 
-    cout << "burning data eeprom,\n";
+    std::cout << "burning data eeprom,\n";
     while (pic.address () < 0x440) {
       if (EX_OK != (retval = program_location (pic,
 					       pic.address () + 0x2100 - 0x400,
@@ -302,19 +302,19 @@
 	return retval;
       pic.command (picport::inc_addr);
       if (got_signal) {
-	cerr << "Exiting.\n";
+	std::cerr << "Exiting.\n";
 	return EX_UNAVAILABLE;
       }
     }
     
-    cout << "burning id words,\n";
+    std::cout << "burning id words,\n";
     pic.command (picport::load_conf, 0x3fff); // dummy value
     while (pic.address () < 0x2004) {
       if (EX_OK != (retval = program_location (pic, pic.address (), false)))
 	return retval;
       pic.command (picport::inc_addr);
       if (got_signal) {
-	cerr << "Exiting.\n";
+	std::cerr << "Exiting.\n";
 	return EX_UNAVAILABLE;
       }
     }
@@ -323,17 +323,17 @@
     pic.command (picport::inc_addr);
     pic.command (picport::inc_addr);
     
-    cout << "burning fuses,\n";
+    std::cout << "burning fuses,\n";
     if (EX_OK != (retval = program_location (pic, pic.address (), false)))
       return retval;
-    cout << "done.\n";
+    std::cout << "done.\n";
   }  // scope of pic
 
   signal (SIGTERM, save_t);
   signal (SIGQUIT, save_q);
   signal (SIGINT, save_i);
   if (got_signal) {
-    cerr << "Exiting.\n";
+    std::cerr << "Exiting.\n";
     return EX_UNAVAILABLE;
   }
 
@@ -352,47 +352,47 @@
   {
     picport pic (port);
 
-    cout << "Reading program eeprom,\n";
+    std::cout << "Reading program eeprom,\n";
     while (pic.address () < 0x400) {
       if (-1 == (pgm [pic.address ()] = pic.command (picport::data_from_prog))) {
-	cerr << port << ':' << hex << setfill ('0') << setw (4) << pic.address () << dec
+	std::cerr << port << ':' << std::hex << std::setfill ('0') << std::setw (4) << pic.address () << std::dec
 	     << ":unable to read pic\n";
 	return EX_IOERR;
       }
       pic.command (picport::inc_addr);
       if (got_signal) {
-	cerr << "Exiting.\n";
+	std::cerr << "Exiting.\n";
 	return EX_UNAVAILABLE;
       }
     }
 
-    cout << "reading data eeprom,\n";
+    std::cout << "reading data eeprom,\n";
     while (pic.address () < 0x440) {
       if (-1 == (pgm [pic.address () + 0x2100-0x400]
 		 = pic.command (picport::data_from_data))) {
-	cerr << port << ':' << hex << setfill ('0') << setw (4)
-	     << pic.address () + 0x2100-0x400 << dec
+	std::cerr << port << ':' << std::hex << std::setfill ('0') << std::setw (4)
+	     << pic.address () + 0x2100-0x400 << std::dec
 	     << ":unable to read pic data memory\n";
 	return EX_IOERR;
       }
       pic.command (picport::inc_addr);
       if (got_signal) {
-	cerr << "Exiting.\n";
+	std::cerr << "Exiting.\n";
 	return EX_UNAVAILABLE;
       }
     }
     pic.command (picport::load_conf, 0);
 
-    cout << "reading id words,\n";
+    std::cout << "reading id words,\n";
     while (pic.address () < 0x2004) {
       if (-1 == (pgm [pic.address ()] = pic.command (picport::data_from_prog))) {
-	cerr << port << ':' << hex << setfill ('0') << setw (4) << pic.address () << dec
+	std::cerr << port << ':' << std::hex << std::setfill ('0') << std::setw (4) << pic.address () << std::dec
 	     << ":unable to read pic id words\n";
 	return EX_IOERR;
       }
       pic.command (picport::inc_addr);
       if (got_signal) {
-	cerr << "Exiting.\n";
+	std::cerr << "Exiting.\n";
 	return EX_UNAVAILABLE;
       }
     }
@@ -402,20 +402,20 @@
     pic.command (picport::inc_addr);
 
     // fuses
-    cout << "reading fuses,\n";
+    std::cout << "reading fuses,\n";
     if (-1 == (pgm [pic.address ()] = pic.command (picport::data_from_prog))) {
-      cerr << port << ':' << hex << setfill ('0') << setw (4) << pic.address () << dec
+      std::cerr << port << ':' << std::hex << std::setfill ('0') << std::setw (4) << pic.address () << std::dec
 	   << ":unable to read pic fuses\n";
       return EX_IOERR;
     }
-    cout << "done.\n";
+    std::cout << "done.\n";
   } // pic scope
 
   signal (SIGTERM, save_t);
   signal (SIGQUIT, save_q);
   signal (SIGINT, save_i);
   if (got_signal) {
-    cerr << "Exiting.\n";
+    std::cerr << "Exiting.\n";
     return EX_UNAVAILABLE;
   }
 
