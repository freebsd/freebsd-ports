--- trackercore/nsf_export.cpp.orig	Mon Apr 22 10:40:35 2002
+++ trackercore/nsf_export.cpp	Fri Dec 27 21:57:08 2002
@@ -72,7 +72,7 @@
 	write_byte(0x8d); write_byte(p_register_addr&0xFF); write_byte(p_register_addr >> 8); // STA $p_register_addr
 }
 
-void NSF_Export::update_voice_data(Uint8 p_voice, bool write_chunk=false) {
+void NSF_Export::update_voice_data(Uint8 p_voice, bool write_chunk) {
 
 	if ((p_voice<2) || (p_voice==3)) {
 	
