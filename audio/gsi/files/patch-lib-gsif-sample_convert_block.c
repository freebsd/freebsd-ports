--- lib/gsif/sample/convert_block.c.orig	2001-01-30 13:28:09.000000000 +0100
+++ lib/gsif/sample/convert_block.c	2007-12-06 17:04:45.000000000 +0100
@@ -122,9 +122,9 @@
 			break;
 		case GSI_16BIT:
 #ifdef SYSCONFIG_LITTLE_ENDIAN_MACHINE
-			input_val = (int) (int16) ( ((*input++) << 8) | (*input++) );
+			input_val = (int) (int16) ( (*input++ << 8) | *input++ );
 #else
-			input_val = *((int16 *)input)++;
+			input_val = *input++;
 #endif
 			break;
 		case GSI_8BIT_SIGNED:
@@ -132,9 +132,9 @@
 			break;
 		case GSI_16BIT_LE:
 #ifdef SYSCONFIG_LITTLE_ENDIAN_MACHINE
-			input_val = *((int16 *)input)++;
+			input_val = *input++;
 #else
-			input_val = (int) (int16) (*input++ | ((*input++) << 8) );
+			input_val = (int) (int16) (*(input++) | ((*input++) << 8) );
 #endif
 			break;
 		case GSI_24BIT:
@@ -170,7 +170,7 @@
 			*output++ = (input_val >> 8) & 255;
 			*output++ = (input_val & 255);
 #else
-			*((int16 *) output)++ = input_val;
+			*output++ = input_val;
 #endif
 			break;
 		case GSI_8BIT_SIGNED:
@@ -178,7 +178,7 @@
 			break;
 		case GSI_16BIT_LE:
 #ifdef SYSCONFIG_LITTLE_ENDIAN_MACHINE
-			*((int16 *) output)++ = input_val;
+			*output++ = input_val;
 #else
 			*output++ = (input_val >> 8) & 255;
 			*output++ = (input_val & 255);
