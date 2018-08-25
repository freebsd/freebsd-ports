src/fmgen/psg.cpp:121:37: error: constant expression evaluates to -1 which cannot be narrowed to type 'uint8' (aka 'unsigned char') [-Wc++11-narrowing]
        static uint8 table3[4] = {  0,  1, -1,  0 };
                                           ^~

--- src/fmgen/psg.cpp.orig	2003-09-05 15:06:43 UTC
+++ src/fmgen/psg.cpp
@@ -118,7 +118,7 @@ void PSG::MakeEnvelopTable()
 		2,2, 2,0, 2,1, 2,3, 1,1, 1,3, 1,2, 1,0,
 	};
 	static uint8 table2[4] = {  0,  0, 31, 31 };
-	static uint8 table3[4] = {  0,  1, -1,  0 };
+	static uint8 table3[4] = {  0,  1, 255,  0 };
 
 	uint* ptr = enveloptable[0];
 
