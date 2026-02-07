--- ./shared/shared.c.orig	Tue May 23 20:05:59 2006
+++ ./shared/shared.c	Tue May 23 20:06:00 2006
@@ -539,3 +539,112 @@
 		dest--;
 	}
 }
+
+/*
+==============================================================================
+
+	BYTE ORDER FUNCTIONS
+
+==============================================================================
+*/
+
+qBool	bigendien;
+
+/*
+ * Can't just use function pointers, or DLL linkage can mess up when qcommon
+ * is included in multiple places.
+ */
+
+int16	(*_LittleShort) (int16 l);
+int32	(*_LittleLong) (int32 l);
+float	(*_LittleFloat) (float l);
+int16	(*_BigShort) (int16 l);
+int32	(*_BigLong) (int32 l);
+float	(*_BigFloat) (float l);
+
+int16	LittleShort (int16 l) { return _LittleShort(l); }
+int32	LittleLong (int32 l) { return _LittleLong(l); }
+float	LittleFloat (float l) { return _LittleFloat(l); }
+int16	BigShort (int16 l) { return _BigShort(l); }
+int32	BigLong (int32 l) { return _BigLong(l); }
+float	BigFloat (float l) { return _BigFloat(l); }
+
+int16	ShortNoSwap (int16 l) { return l; }
+int32	LongNoSwap (int32 l) { return l; }
+float	FloatNoSwap (float f) { return f; }
+
+int16 ShortSwap (int16 s)
+{
+	union {
+		byte	b[2];
+		int16	s;
+	} in, out;
+
+	in.s = s;
+
+	out.b[0] = in.b[1];
+	out.b[1] = in.b[0];
+
+	return out.s;
+}
+
+int32	LongSwap (int32 l)
+{
+	union {
+		byte	b[4];
+		int		l;
+	} in, out;
+
+	in.l = l;
+
+	out.b[0] = in.b[3];
+	out.b[1] = in.b[2];
+	out.b[2] = in.b[1];
+	out.b[3] = in.b[0];
+
+	return out.l;
+}
+
+float	FloatSwap (float f)
+{
+	union {
+		byte	b[4];
+		float	f;
+	} in, out;
+
+	in.f = f;
+
+	out.b[0] = in.b[3];
+	out.b[1] = in.b[2];
+	out.b[2] = in.b[1];
+	out.b[3] = in.b[0];
+
+	return out.f;
+}
+
+/*
+ * Swap_Init
+ * Set the byte swapping variables in a portable manner.
+ */
+void Swap_Init (void)
+{
+	byte	swaptest[2] = {1, 0};
+
+	if (*(int16 *)swaptest == 1) {
+		bigendien = qFalse;
+		_LittleShort = ShortNoSwap;
+		_LittleLong = LongNoSwap;
+		_LittleFloat = FloatNoSwap;
+		_BigShort = ShortSwap;
+		_BigLong = LongSwap;
+		_BigFloat = FloatSwap;
+	} else {
+		bigendien = qTrue;
+		_LittleShort = ShortSwap;
+		_LittleLong = LongSwap;
+		_LittleFloat = FloatSwap;
+		_BigShort = ShortNoSwap;
+		_BigLong = LongNoSwap;
+		_BigFloat = FloatNoSwap;
+	}
+}
