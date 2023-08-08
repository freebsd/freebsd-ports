--- sources/xray_re/xr_reader.h.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_reader.h
@@ -79,11 +79,10 @@ class xr_reader { (public)
 	void		r_sdir(fvector3& v);
 	void		r_packet(xr_packet& packet, size_t size);
 
-	template<typename T> struct f_r: public std::binary_function<T, xr_reader, void> {};
-	struct f_r_sz: public f_r<std::string> {
+	struct f_r_sz {
 		void operator()(std::string& s, xr_reader& r) { r.r_sz(s); }
 	};
-	template<typename T> struct f_r_new: public f_r<T> {
+	template<typename T> struct f_r_new {
 		explicit f_r_new(void (T::*_pmf)(xr_reader& r)): pmf(_pmf) {}
 		void operator()(T*& p, xr_reader& r) { T* _p = new T; (_p->*pmf)(r); p = _p; }
 	private:
