--- core/image.cpp.orig	2018-01-10 18:34:14 UTC
+++ core/image.cpp
@@ -1518,8 +1518,8 @@ Error Image::_decompress_bc() {
 					col_b |= src[2];
 
 					uint8_t table[4][4] = {
-						{ (col_a >> 11) << 3, ((col_a >> 5) & 0x3f) << 2, ((col_a)&0x1f) << 3, 255 },
-						{ (col_b >> 11) << 3, ((col_b >> 5) & 0x3f) << 2, ((col_b)&0x1f) << 3, 255 },
+						{ static_cast<uint8_t>((col_a >> 11) << 3), static_cast<uint8_t>(((col_a >> 5) & 0x3f) << 2), static_cast<uint8_t>(((col_a)&0x1f) << 3), 255 },
+						{ static_cast<uint8_t>((col_b >> 11) << 3), static_cast<uint8_t>(((col_b >> 5) & 0x3f) << 2), static_cast<uint8_t>(((col_b)&0x1f) << 3), 255 },
 						{ 0, 0, 0, 255 },
 						{ 0, 0, 0, 255 }
 					};
@@ -1611,8 +1611,8 @@ Error Image::_decompress_bc() {
 					col_b |= src[8 + 2];
 
 					uint8_t table[4][4] = {
-						{ (col_a >> 11) << 3, ((col_a >> 5) & 0x3f) << 2, ((col_a)&0x1f) << 3, 255 },
-						{ (col_b >> 11) << 3, ((col_b >> 5) & 0x3f) << 2, ((col_b)&0x1f) << 3, 255 },
+						{ static_cast<uint8_t>((col_a >> 11) << 3), static_cast<uint8_t>(((col_a >> 5) & 0x3f) << 2), static_cast<uint8_t>(((col_a)&0x1f) << 3), 255 },
+						{ static_cast<uint8_t>((col_b >> 11) << 3), static_cast<uint8_t>(((col_b >> 5) & 0x3f) << 2), static_cast<uint8_t>(((col_b)&0x1f) << 3), 255 },
 						{ 0, 0, 0, 255 },
 						{ 0, 0, 0, 255 }
 					};
@@ -1722,8 +1722,8 @@ Error Image::_decompress_bc() {
 					col_b |= src[8 + 2];
 
 					uint8_t table[4][4] = {
-						{ (col_a >> 11) << 3, ((col_a >> 5) & 0x3f) << 2, ((col_a)&0x1f) << 3, 255 },
-						{ (col_b >> 11) << 3, ((col_b >> 5) & 0x3f) << 2, ((col_b)&0x1f) << 3, 255 },
+						{ static_cast<uint8_t>((col_a >> 11) << 3), static_cast<uint8_t>(((col_a >> 5) & 0x3f) << 2), static_cast<uint8_t>(((col_a)&0x1f) << 3), 255 },
+						{ static_cast<uint8_t>((col_b >> 11) << 3), static_cast<uint8_t>(((col_b >> 5) & 0x3f) << 2), static_cast<uint8_t>(((col_b)&0x1f) << 3), 255 },
 						{ 0, 0, 0, 255 },
 						{ 0, 0, 0, 255 }
 					};
