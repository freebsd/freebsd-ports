--- Alc/ALu.c.orig	2013-05-23 08:00:01.000000000 +0200
+++ Alc/ALu.c	2013-05-23 08:01:20.000000000 +0200
@@ -912,24 +912,27 @@
 }
 
 
-static __inline ALfloat aluF2F(ALfloat val)
-{ return val; }
-static __inline ALint aluF2I(ALfloat val)
+static __inline ALint aluF2I25(ALfloat val)
 {
     /* Clamp the value between -1 and +1. This handles that without branching. */
     val = val+1.0f - fabsf(val-1.0f);
     val = (val-2.0f + fabsf(val+2.0f)) * 0.25f;
-    /* Convert to a signed integer, between -2147483647 and +2147483647. */
-    return fastf2i((ALfloat)(val*2147483647.0));
+    /* Convert to a signed integer, between -16777215 and +16777215. */
+    return fastf2i(val*16777215.0f);
 }
+
+static __inline ALfloat aluF2F(ALfloat val)
+{ return val; }
+static __inline ALint aluF2I(ALfloat val)
+{ return aluF2I25(val)<<7; }
 static __inline ALuint aluF2UI(ALfloat val)
 { return aluF2I(val)+2147483648u; }
 static __inline ALshort aluF2S(ALfloat val)
-{ return aluF2I(val)>>16; }
+{ return aluF2I25(val)>>9; }
 static __inline ALushort aluF2US(ALfloat val)
 { return aluF2S(val)+32768; }
 static __inline ALbyte aluF2B(ALfloat val)
-{ return aluF2I(val)>>24; }
+{ return aluF2I25(val)>>17; }
 static __inline ALubyte aluF2UB(ALfloat val)
 { return aluF2B(val)+128; }
 
