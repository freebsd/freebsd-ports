--- sources/xray_re/xr_writer.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_writer.cxx
@@ -176,7 +176,7 @@ void xr_ini_writer::open_section(std::string format, .
 #if defined(_MSC_VER) && _MSC_VER >= 1400
 	int n = vsprintf_s(buf, sizeof(buf), format.c_str(), ap);
 #else
-	int n = vsnprintf(buf, sizeof(buf), format, ap);
+	int n = vsnprintf(buf, sizeof(buf), format.c_str(), ap);
 #endif
 	va_end(ap);
 	if (n == 0)
