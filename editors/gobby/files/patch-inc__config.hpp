--- ./inc/config.hpp.orig	2012-01-30 01:27:51.000000000 +0100
+++ ./inc/config.hpp	2014-07-24 13:11:27.000000000 +0200
@@ -31,6 +31,19 @@
 #include <libxml++/nodes/element.h>
 #include <libxml++/nodes/textnode.h>
 
+
+namespace serialise
+{
+template<>
+class default_context_to<Glib::ustring>: public context_base_to<Glib::ustring>
+{
+public:
+	typedef Glib::ustring data_type;
+
+	virtual std::string to_string(const data_type& from) const;
+};
+}
+
 namespace Gobby
 {
 
@@ -460,15 +473,6 @@
 };
 
 template<>
-class default_context_to<Glib::ustring>: public context_base_to<Glib::ustring>
-{
-public:
-	typedef Glib::ustring data_type;
-
-	virtual std::string to_string(const data_type& from) const;
-};
-
-template<>
 class default_context_from<Glib::ustring>:
 	public context_base_from<Glib::ustring>
 {
