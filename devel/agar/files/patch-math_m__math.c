Index: math/m_math.c
===================================================================
--- math/m_math.c.orig	2015-08-24 07:59:46 UTC
+++ math/m_math.c
@@ -61,7 +61,14 @@ static size_t
 PrintTime(AG_FmtString *fs, char *dst, size_t dstSize)
 {
 	M_Time *t = AG_FMTSTRING_ARG(fs);
-	return AG_UnitFormat((double)(*t), agTimeUnits, dst, dstSize);
+#ifdef ENABLE_GUI
+	if (agGUI) {
+		return AG_UnitFormat((double)(*t), agTimeUnits, dst, dstSize);
+	} else
+#endif
+	{
+		return Snprintf(dst, dstSize, "%f", (double)(*t));
+	}
 }
 static size_t
 PrintComplex(AG_FmtString *fs, char *dst, size_t dstSize)
