--- ibitstream.cc.orig	1994-06-23 12:14:35 UTC
+++ ibitstream.cc
@@ -29,7 +29,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <iostream.h>
+#include <iostream>
 #include "all.h"
 #include "ibitstream.h"
 
@@ -50,7 +50,7 @@ Ibitstream::Ibitstream (const char *file
 {
   if ((fd = open (filename, O_RDONLY, 0)) < 0)
   {
-    cerr << "can't open file \"" << filename << "\" for reading!\n";
+    std::cerr << "can't open file \"" << filename << "\" for reading!\n";
     exit (1);
   }
   wordpointer = buffer;
@@ -64,7 +64,7 @@ Ibitstream::~Ibitstream (void)				// des
 }
 
 
-bool Ibitstream::get_header (uint32 *headerstring)
+boolean Ibitstream::get_header (uint32 *headerstring)
 {
   int readvalue;
 
@@ -102,13 +102,13 @@ bool Ibitstream::get_header (uint32 *hea
 }
 
 
-bool Ibitstream::read_frame (uint32 bytesize)
+boolean Ibitstream::read_frame (uint32 bytesize)
 {
   int readvalue;
 
   if (bytesize > (bufferintsize << 2))
   {
-    cerr << "Internal error: framelength > bufferlength?!\n";
+    std::cerr << "Internal error: framelength > bufferlength?!\n";
     exit (1);
   }
 
@@ -170,7 +170,7 @@ uint32 Ibitstream::get_bits (uint32 numb
 #ifdef DEBUG
   if (number_of_bits < 1 || number_of_bits > 16)
   {
-    cerr << "illegal parameter in Ibitstream::get_bits() !\n";
+    std::cerr << "illegal parameter in Ibitstream::get_bits() !\n";
     exit (1);
   }
 #endif
@@ -184,7 +184,7 @@ uint32 Ibitstream::get_bits (uint32 numb
       bitindex = 0;
       if ((char *)++wordpointer > (char *)buffer + framesize)
       {
-	cerr << "Ibitstream::get_bits(): no more bits in buffer!\n";
+	std::cerr << "Ibitstream::get_bits(): no more bits in buffer!\n";
 	exit (1);
       }
     }
@@ -197,7 +197,7 @@ uint32 Ibitstream::get_bits (uint32 numb
   *(int16 *)&returnvalue = *((int16 *)wordpointer + 1);
   if ((char *)++wordpointer > (char *)buffer + framesize)
   {
-    cerr << "Ibitstream::get_bits(): no more bits in buffer!\n";
+    std::cerr << "Ibitstream::get_bits(): no more bits in buffer!\n";
     exit (1);
   }
   *((int16 *)&returnvalue + 1) = *(int16 *)wordpointer;
@@ -205,7 +205,7 @@ uint32 Ibitstream::get_bits (uint32 numb
   *((int16 *)&returnvalue + 1) = *(int16 *)wordpointer;
   if ((char *)++wordpointer > (char *)buffer + framesize)
   {
-    cerr << "Ibitstream::get_bits(): no more bits in buffer!\n";
+    std::cerr << "Ibitstream::get_bits(): no more bits in buffer!\n";
     exit (1);
   }
   *(int16 *)&returnvalue = *((int16 *)wordpointer + 1);
