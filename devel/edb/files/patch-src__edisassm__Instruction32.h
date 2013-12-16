--- ./src/edisassm/Instruction32.h.orig	2011-12-20 22:04:57.000000000 +0100
+++ ./src/edisassm/Instruction32.h	2013-11-20 18:01:17.389439581 +0100
@@ -290,7 +290,6 @@
 template <int16_t IMM>
 void Instruction<M>::decode_const_Iw(const uint8_t *buf) {
 	UNUSED(buf);
-	UNUSED(size);
 
 	operand_t &operand = next_operand();
 
