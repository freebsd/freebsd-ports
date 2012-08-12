--- ctronome.h.orig	2012-07-22 15:14:52.000000000 +0400
+++ ctronome.h	2012-07-22 15:15:31.000000000 +0400
@@ -1,4 +1,6 @@
 #include <sys/soundcard.h>
+#include <stdint.h>
+
 #define MYNAME "ctronome"
 #define VERSION "0.5.3"
 #define CREDITS "homepage: http://ctronome.kign.org/\n"
@@ -28,9 +30,9 @@
            for defaults/limits and required WAV format see README\n"
 
 /* my lazy type definitions */
-typedef unsigned long int DWORD;
-typedef unsigned short int WORD;
-typedef unsigned char BYTE;
+typedef uint32_t DWORD;
+typedef uint16_t WORD;
+typedef uint8_t BYTE;
 typedef DWORD dword;
 typedef WORD word;
 typedef BYTE byte;
