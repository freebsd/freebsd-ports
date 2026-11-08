The pre-generated bootstrap compiler reinterprets the first 8 bytes of an
Int128 (an array of uint32 words, least significant first) as uint64 when
folding shr, which only works on little-endian. Same fix as upstream
e97b0bb541ee (castToUInt64) applied to the generated C.

--- c_code/5_2/@msemfold.nim.c.orig	2026-09-08 04:06:18 UTC
+++ c_code/5_2/@msemfold.nim.c
@@ -3172,12 +3172,12 @@
 		T183_ = getInt__ast_u7046(a_p2);
 		if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;
 		LOC182.source = T183_;
-		a_2 = LOC182.dest;
+		a_2 = ((NU64)(LOC182.source.udata[0]) | ((NU64)(LOC182.source.udata[1]) << 32));
 		nimZeroMem((void*)(&T185_), sizeof(tyObject_Int128__Moyhy3H7f18q9axhPc7Yt9bg));
 		T185_ = getInt__ast_u7046(b_p3);
 		if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;
 		LOC184.source = T185_;
-		b_2 = (NU64)(LOC184.dest & ((NU64) ((NI64)((NI64)((*(*n_p1).typField).size * IL64(8)) - IL64(1)))));
+		b_2 = (NU64)(((NU64)(LOC184.source.udata[0]) | ((NU64)(LOC184.source.udata[1]) << 32)) & ((NU64) ((NI64)((NI64)((*(*n_p1).typField).size * IL64(8)) - IL64(1)))));
 		{
 			tyObject_TType__8qAQZfpTDk89aeclTNn4d9cg* colontmpD__6;
 			if (!((NU64)(0ULL) < (NU64)(b_2))) goto LA188_;
