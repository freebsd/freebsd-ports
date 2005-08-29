--- src/nes/km6502/km6502ot.h.orig	Sun Jan  7 05:18:05 2001
+++ src/nes/km6502/km6502ot.h	Thu Aug 18 16:47:59 2005
@@ -1,35 +1,35 @@
 #define OPxx(i)
 #define OP__(i) \
-	case 0x##i##: \
-		Opcode##i##(__THISP); \
+	case 0x##i : \
+		Opcode##i (__THISP); \
 		break;
 #define OP_d(i) \
-	case 0x##i##: \
+	case 0x##i : \
 		if (__THIS__.P & D_FLAG) \
-			D_Opco##i##(__THISP); \
+			D_Opco##i (__THISP); \
 		else \
-			Opcode##i##(__THISP); \
+			Opcode##i (__THISP); \
 		break;
 #if BUILD_HUC6280
 #define OPtd(i) \
-	case 0x##i##: \
+	case 0x##i : \
 		if (__THIS__.P & T_FLAG) \
 			if (__THIS__.P & D_FLAG) \
-				TD_Opc##i##(__THISP); \
+				TD_Opc##i (__THISP); \
 			else \
-				T_Opco##i##(__THISP); \
+				T_Opco##i (__THISP); \
 		else \
 			if (__THIS__.P & D_FLAG) \
-				D_Opco##i##(__THISP); \
+				D_Opco##i (__THISP); \
 			else \
-				Opcode##i##(__THISP); \
+				Opcode##i (__THISP); \
 		break;
 #define OPt_(i) \
-	case 0x##i##: \
+	case 0x##i : \
 		if (__THIS__.P & T_FLAG) \
-			T_Opco##i##(__THISP); \
+			T_Opco##i (__THISP); \
 		else \
-			Opcode##i##(__THISP); \
+			Opcode##i (__THISP); \
 		break;
 #else
 #define OPtd OP_d
