--- src/events.cc.orig	1999-06-09 12:14:04.000000000 +0200
+++ src/events.cc	2007-12-18 19:09:20.000000000 +0100
@@ -30,7 +30,8 @@
 # include <config.h>
 #endif
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #ifdef STDC_HEADERS
 # include <string.h>
@@ -267,8 +268,7 @@
 //
 //-------------------------------------------------------------------------
 
-midiMetaTextEvent::midiMetaTextEvent(long int dT = 0L, midiEvent *n = 0, 
-				     char *t = 0) :
+midiMetaTextEvent::midiMetaTextEvent(long int dT, midiEvent *n, char *t) :
   midiEvent(dT, n)
 {
   if(t == 0)
@@ -602,10 +602,10 @@
 //
 //-------------------------------------------------------------------------
 
-midiSequencerSpecificEvent::midiSequencerSpecificEvent(long int dT = 0L, 
-						       midiEvent *n = 0, 
-						       unsigned char *d = 0, 
-						       int l = 0) :
+midiSequencerSpecificEvent::midiSequencerSpecificEvent(long int dT, 
+						       midiEvent *n, 
+						       unsigned char *d, 
+						       int l) :
   midiEvent(dT, n)
 {
   if(d == 0)
