--- sources/xray_re/xr_writer.h.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_writer.h
@@ -268,9 +268,9 @@ template<typename T, typename F> inline void xr_ini_wr
 template<typename T, typename F> inline void xr_ini_writer::w_ini_seq(const T& container, F write, const char* prefix)
 {
 	char buf[1024];
+	typename T::const_iterator it = container.begin(), end = container.end();
 
-	for (uint32_t id = 0, typename T::const_iterator it = container.begin(),
-			end = container.end(); it != end; ++it, ++id) {
+	for (uint32_t id = 0; it != end; ++it, ++id) {
 #if defined(_MSC_VER) && _MSC_VER >= 1400
 		int n = sprintf_s(buf, sizeof(buf), "%s_%04d", prefix, id);
 #else
