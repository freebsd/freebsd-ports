--- ./estring.h.orig	2007-07-14 11:31:16.000000000 +0200
+++ ./estring.h	2007-07-14 11:35:07.000000000 +0200
@@ -255,21 +255,21 @@
 	estring_value m_value;
 
 	template <class T>
-	void estring::T_fraction_to_strings(const T& a_t,
+	void T_fraction_to_strings(const T& a_t,
 		value_type& a_ws, value_type& a_fs);
 
 	template <class T>
-	void estring::T_integral_to_string(const T& a_t, value_type& a_str);
+	void T_integral_to_string(const T& a_t, value_type& a_str);
 
 	template <class T>
-	void estring::T_string_to_integral(const value_type& a_str, T& a_t) const;
+	void T_string_to_integral(const value_type& a_str, T& a_t) const;
 
 	template <class T>
-	void estring::T_string_to_signed_integral(const value_type& a_str, T& a_t)
+	void T_string_to_signed_integral(const value_type& a_str, T& a_t)
 		const;
 	
 	template <class T>
-	void estring::T_string_to_fractional(const value_type& a_str, T& a_t) const;
+	void T_string_to_fractional(const value_type& a_str, T& a_t) const;
 };
 
 #endif
