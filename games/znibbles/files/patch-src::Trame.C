--- src/Trame.C	Mon May 10 08:57:09 1999
+++ src/Trame.C	Sat Oct 26 00:41:28 2002
@@ -39,7 +39,7 @@
 # include <config.h>
 #endif
 
-#include <iostream.h>
+#include <iostream>
 
 #include <stdlib.h>
 #include <stdio.h>
@@ -93,11 +93,11 @@
 #endif
 
 #ifdef DEBUG_TRACE
-  cout << "sending: [";
+  std::cout << "sending: [";
   printf("%02x %02x] ", rbuf[0], rbuf[1]);
   for (int i = 0; i < len; i++)
     printf("%02x ", (unsigned int) buf[i]);
-  cout << endl;   
+  std::cout << std::endl;   
 #endif
 
   // always write at least 4 bytes
@@ -161,19 +161,19 @@
     return -1;
   
   if (retval <= 0) {
-    cerr << "trame.fuck. error=" << errno << endl;
+    std::cerr << "trame.fuck. error=" << errno << std::endl;
     switch(errno) {
     case EBADF:
-      cerr << "  EBADF invalid file desc " << endl;
+      std::cerr << "  EBADF invalid file desc " << std::endl;
       break;
     case EINTR:
-      cerr << "  EINTR: signal was caught " << endl;
+      std::cerr << "  EINTR: signal was caught " << std::endl;
       break;
     case EINVAL:
-      cerr << "  EINVAL n is negative " << endl;
+      std::cerr << "  EINVAL n is negative " << std::endl;
       break;
     case ENOMEM:
-      cerr << "  ENOMEM unable to allocate memory " << endl;
+      std::cerr << "  ENOMEM unable to allocate memory " << std::endl;
       break;
     }
 
@@ -196,14 +196,14 @@
     
     if (xx < 0) {
       if (errno == 0)
-	cerr << "Trame::receive_from(): error #0!" << endl;
+	std::cerr << "Trame::receive_from(): error #0!" << std::endl;
       else
-	cerr << "Trame::receive_from(): real error..." << endl;
+	std::cerr << "Trame::receive_from(): real error..." << std::endl;
       return -1;
     } else {
       if (xx != len - 2) {
-	cerr << "Trame::receive_from(): short read (read " 
-	     << xx + 2 << " instead of " << len << ")" << endl;
+	std::cerr << "Trame::receive_from(): short read (read " 
+	     << xx + 2 << " instead of " << len << ")" << std::endl;
 	return -1;
       }
     }
@@ -212,11 +212,11 @@
   cursize = len;
   
 #ifdef DEBUG_TRACE
-  cout << "receivd: [";
+  std::cout << "receivd: [";
   printf("%02x %02x] ", rbuf[0], rbuf[1]);
   for (int i = 0; i < len; i++)
     printf("%02x ", (int) buf[i]);
-  cout << endl;
+  std::cout << std::endl;
 #endif
   
 #ifdef DEBUG_LOAD
@@ -381,7 +381,7 @@
     idx += 2;
   }
   else {
-    cerr << "bordel dans get_short()" << endl;
+    std::cerr << "bordel dans get_short()" << std::endl;
     sh = -1;
   }
   
@@ -408,7 +408,7 @@
     return val;
   }
   else
-    cerr << "bordel dans peek_int()" << endl;
+    std::cerr << "bordel dans peek_int()" << std::endl;
   
   return -1;
 }
@@ -423,7 +423,7 @@
     idx += 4;
   }
   else {
-    cerr << "bordel dans get_int()" << endl;
+    std::cerr << "bordel dans get_int()" << std::endl;
     sh = -1;
   }
 
@@ -454,10 +454,10 @@
 
 void Trame::dump_left()
 {
-  cerr << "[ ";
+  std::cerr << "[ ";
   while (idx < cursize) 
-    cerr << (int) buf[idx++] << " ";
-  cerr << "]" << endl;
+    std::cerr << (int) buf[idx++] << " ";
+  std::cerr << "]" << std::endl;
 }
 
 
