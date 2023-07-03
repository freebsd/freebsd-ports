--- sources/xray_re/xr_writer.h.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_writer.h
@@ -68,12 +68,13 @@ class xr_writer { (public)
 
 	void		w_packet(const xr_packet& packet);
 
-	template<typename T> struct f_w: public std::binary_function<T, xr_writer, void> {};
-	struct f_w_sz: public f_w<std::string> {
+	struct f_w_sz {
 		void operator()(const std::string& s, xr_writer& w) { w.w_sz(s); }
 	};
-	template<typename T> struct f_w_const: public std::const_mem_fun1_t<void, T, xr_writer&> {
-		explicit f_w_const(void (T::*_pmf)(xr_writer& w) const): std::const_mem_fun1_t<void, T, xr_writer&>(_pmf) {}
+	template<typename T> struct f_w_const {
+		void (T::*_m_f)(xr_writer&) const;
+		explicit f_w_const(void (T::*_pmf)(xr_writer& w) const): _m_f(_pmf) {}
+		void operator()(const T* t, xr_writer& w) const { (t->*_m_f)(w); }
 	};
 
 private:
@@ -268,9 +269,9 @@ template<typename T, typename F> inline void xr_ini_wr
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
