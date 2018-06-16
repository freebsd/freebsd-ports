--- src/texture.hpp.orig	2018-06-16 11:06:31.462187000 +0300
+++ src/texture.hpp	2018-06-16 11:11:11.775394000 +0300
@@ -58,7 +58,7 @@
 	unsigned int get_id() const;
 	static void set_current_texture(unsigned int id);
 	void set_as_current_texture() const;
-	bool valid() const { return id_; }
+	bool valid() const { return static_cast<bool>(id_); }
 
 	static texture get(const std::string& str, int options=0);
 	static texture get(const std::string& str, const std::string& algorithm);
