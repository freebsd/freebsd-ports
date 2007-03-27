--- ./advance/menu/emulator.h.orig	Tue Dec 27 12:03:40 2005
+++ ./advance/menu/emulator.h	Tue Mar 27 14:49:00 2007
@@ -41,7 +41,7 @@
 	tristate_t exclude_missing_effective;
 	tristate_t exclude_missing_orig;
 
-	std::string emulator::attrib_compile(const std::string& value0, const std::string& value1);
+	std::string attrib_compile(const std::string& value0, const std::string& value1);
 
 	std::string name;
 
@@ -363,7 +363,7 @@
 };
 
 class generic : public emulator {
-	bool generic::load_info(game_set& gar);
+	bool load_info(game_set& gar);
 public:
 	generic(const std::string& Aname, const std::string& Aexe_path, const std::string& Acmd_arg);
 
