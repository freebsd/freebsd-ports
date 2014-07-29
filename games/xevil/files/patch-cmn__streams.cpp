--- cmn/streams.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/streams.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -31,12 +31,13 @@
 #include "utils.h"
 #include "neth.h" // needed for recv, send, recvfrom, sendto
 
-#include <iostream.h>
+#include <iostream>
 
 #include "streams.h"
 #include "xetp.h" // yuck, need this for XETP::versionStr
 
 
+using namespace std;
 
 Checksum GenericStream::compute_checksum(u_char *data,int len) {
   Checksum c = 0;
@@ -205,7 +206,7 @@
   
 
 
-Boolean NetOutStream::write(void *buf,int size) {
+Boolean NetOutStream::write(const void *buf,int size) {
   if (!isAlive) {
     return False;
   }
@@ -518,7 +519,7 @@
 
 
 
-Boolean UDPOutStream::write(void *buf,int size) {
+Boolean UDPOutStream::write(const void *buf,int size) {
   if (!isAlive) {
     return False;
   }
