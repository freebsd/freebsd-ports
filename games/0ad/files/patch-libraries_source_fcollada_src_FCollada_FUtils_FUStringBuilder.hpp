--- libraries/source/fcollada/src/FCollada/FUtils/FUStringBuilder.hpp.orig	2017-07-28 19:57:27 UTC
+++ libraries/source/fcollada/src/FCollada/FUtils/FUStringBuilder.hpp
@@ -26,63 +26,6 @@
 #define SAFE_DELETE_ARRAY(ptr) if (ptr != NULL) { delete [] ptr; ptr = NULL; }
 #endif
 
-template <class Char, class FloatType>
-void FloatToString(FloatType f, Char* sz)
-{
-	Char* buffer = sz + 1;
-	static const int digitCount = 6;
-	int decimal, sign;
-
-	// ecvt rounds the string for us: http://www.datafocus.com/docs/man3/ecvt.3.asp
-	char* end = ecvt(f, digitCount, &decimal, &sign);
-
-	if (sign != 0) (*buffer++) = '-';
-	int count = digitCount;
-	if (decimal > digitCount)
-	{
-		// We use the scientific notation: P.MeX
-		(*buffer++) = (*end++); // P is one character.
-		(*buffer++) = '.';
-
-		// Mantissa (cleaned for zeroes)
-		for (--count; count > 0; --count) if (end[count - 1] != '0') break;
-		for (int i = 0; i < count; ++i) (*buffer++) = (*end++);
-		if (buffer[-1] == '.') --buffer;
-
-		// Exponent
-		(*buffer++) = 'e';
-		uint32 exponent = decimal - 1; // X
-		if (exponent >= 10) (*buffer++) = (Char) ('0' + (exponent / 10));
-		(*buffer++) = (Char) ('0' + (exponent % 10));
-		(*buffer) = 0;
-		return;
-	}
-	else if (decimal > 0)
-	{
-		// Simple number: A.B
-		for (int i = 0; i < decimal; ++i) (*buffer++) = (*end++);
-		if (decimal < digitCount) (*buffer++) = '.';
-		count = digitCount - decimal;
-	}
-	else if (decimal < -digitCount)
-	{
-		// What case is this?
-		decimal = count = 0;
-	}
-	else if (decimal < 0 || (decimal == 0 && *end != '0'))
-	{
-		// Tiny number: 0.Me-X
-		(*buffer++) = '0'; (*buffer++) = '.';
-		for (int i = 0; i < -decimal; ++i) (*buffer++) = '0';
-		count = digitCount + decimal;
-	}
-	for (; count > 0; --count) if (end[count - 1] != '0') break;
-	for (int i = 0; i < count; ++i) (*buffer++) = (*end++);
-	if (decimal == 0 && count == 0) (*buffer++) = '0';
-	if (buffer[-1] == '.') --buffer;
-	(*buffer) = 0;
-}
-
 template <class Char>
 FUStringBuilderT<Char>::FUStringBuilderT(const String& sz)
 {
@@ -234,53 +177,50 @@ void FUStringBuilderT<Char>::append(const FUStringBuil
 template <class Char>
 void FUStringBuilderT<Char>::append(float f)
 {
-#ifdef WIN32
-	// use <float.h> _isnan method to detect the 1.#IND00 NaN.
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN() && !_isnan((double)f))
-#else
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN())
-#endif
-	{
-		if (IsEquivalent(f, 0.0f, std::numeric_limits<float>::epsilon())) append((Char)'0');
-		else
-		{
-			Char sz[128];
-			FloatToString(f, sz);
-			append(sz + 1);
-		}
-	}
-	else if (f == std::numeric_limits<float>::infinity())
-	{ append((Char)'I'); append((Char)'N'); append((Char)'F'); }
-	else if (f == -std::numeric_limits<float>::infinity())
-	{ append((Char)'-'); append((Char)'I'); append((Char)'N'); append((Char)'F'); }
-	else
-	{ append((Char)'N'); append((Char)'a'); append((Char)'N'); }
+	append((double)f);
 }
 
 template <class Char>
 void FUStringBuilderT<Char>::append(double f)
 {
-#ifdef WIN32
-	// use <float.h> _isnan method to detect the .#IND00 NaN.
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN() && !_isnan(f))
-#else
-	if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity() && f != std::numeric_limits<float>::quiet_NaN() && f != std::numeric_limits<float>::signaling_NaN())
-#endif
-	{
-		if (IsEquivalent(f, 0.0, std::numeric_limits<double>::epsilon())) append((Char)'0');
-		else
-		{
-			Char sz[128];
-			FloatToString(f, sz);
-			append(sz + 1);
-		}
+	if (f == -std::numeric_limits<double>::infinity()) {
+		append("-INF");
+		return;
+	} else if (f == std::numeric_limits<double>::infinity()) {
+		append("INF");
+		return;
+	} else if (f != f) {
+		append("NaN");
+		return;
+	} else if (-std::numeric_limits<double>::epsilon() < f && f < std::numeric_limits<double>::epsilon()) {
+		append("0.0E0");
+		return;
 	}
-	else if (f == std::numeric_limits<double>::infinity())
-	{ append((Char)'I'); append((Char)'N'); append((Char)'F'); }
-	else if (f == -std::numeric_limits<double>::infinity())
-	{ append((Char)'-'); append((Char)'I'); append((Char)'N'); append((Char)'F'); }
+
+	if (f < 0.0) {
+		f = -f;
+		append('-');
+	}
+
+	int e = 0;
+// 	e = floor(log10(f));
+// 	f = f / pow(10.0, e);
+
+	if (f < 1.0)
+		for (; f < 1.0; f *= 10.0)
+			e--;
 	else
-	{ append((Char)'N'); append((Char)'a'); append((Char)'N'); }
+		for (; f >= 10.0; f /= 10.0)
+			e++;
+
+	char tmp[10];
+	sprintf(tmp, "%.6g", f);
+	append(tmp);
+	if (tmp[1] == 0) // only one digit, add missing part according canonical representation
+		append(".0");
+
+	sprintf(tmp, "E%d", e);
+	append(tmp);
 }
 
 template <class Char>
