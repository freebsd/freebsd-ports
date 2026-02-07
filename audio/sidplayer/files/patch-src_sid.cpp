--- src/sid.cpp.orig	2004-05-08 11:29:06 UTC
+++ src/sid.cpp
@@ -471,7 +471,7 @@ static filt_t ffreq_hp[256];	// High-pas
 
 // Table for sampled voices
 #ifdef SID_PLAYER
-static const int16 sample_tab[16 * 3] = {
+static const uint16_t sample_tab[16 * 3] = {
 	0x8000, 0x9111, 0xa222, 0xb333, 0xc444, 0xd555, 0xe666, 0xf777,
 	0x0888, 0x1999, 0x2aaa, 0x3bbb, 0x4ccc, 0x5ddd, 0x6eee, 0x7fff,
 
