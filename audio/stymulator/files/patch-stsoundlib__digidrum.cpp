--- ./stsoundlib/digidrum.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./stsoundlib/digidrum.cpp	2010-04-23 13:50:07.000000000 +0200
@@ -30,6 +30,7 @@
 -----------------------------------------------------------------------------*/
 
 #include "YmTypes.h"
+#include "digidrum.h"
 
 static ymu8	sample00[631]={
 		0xCC,0x84,0xB4,0x70,0x90,0x94,0x70,0x80,0x80,0xAC,
@@ -2565,7 +2566,7 @@
 		0x80,0x80,0x80,0x80,0x80,0x80,};
 /***********************************************************/
 
-ymu8 *sampleAdress[40] = {
+ymu8 *sampleAdress[MAX_DIGIDRUM] = {
 		sample00,sample01,sample02,sample03,sample04,sample05,sample06,sample07,
 		sample08,sample09,sample10,sample11,sample12,sample13,sample14,sample15,
 		sample16,sample17,sample18,sample19,sample20,sample21,sample22,sample23,
@@ -2574,7 +2575,7 @@
 
 /***********************************************************/
 
-ymu32 sampleLen[40] = {
+ymu32 sampleLen[MAX_DIGIDRUM] = {
 		  631,  631,  490,  490,  699,  505,  727,  480,
 		 2108, 4231,  378, 1527,  258,  258,  451, 1795,
 		  271,  633, 1379,  147,  139,   85,  150,  507,
