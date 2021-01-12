diff --git a/src/database/data_type.h b/src/database/data_type.h
index 1e9aa40ce..645cb217e 100644
--- src/database/data_type.h
+++ src/database/data_type.h
@@ -52,6 +52,15 @@ template <typename T>
 class data_type : public data_type_base
 {
 public:
+	data_type() {
+		// this check is required for class_initialized variable and,
+		// correspondingly, data_type::initialize_class() call not to
+		// be initialized away
+		if (!class_initialized) {
+			throw std::runtime_error("Never reached");
+		}
+	}
+
 	static T *get(const std::string &identifier)
 	{
 		if (identifier == "none") {
@@ -308,12 +317,7 @@ class data_type : public data_type_base
 	static inline std::map<std::string, qunique_ptr<T>> instances_by_identifier;
 	static inline std::map<std::string, T *> instances_by_alias;
 	static inline data_module_map<std::vector<sml_data>> sml_data_to_process;
-#ifdef __GNUC__
-	//the "used" attribute is needed under GCC, or else this variable will be optimized away (even in debug builds)
-	static inline bool class_initialized [[gnu::used]] = data_type::initialize_class();
-#else
 	static inline bool class_initialized = data_type::initialize_class();
-#endif
 };
 
 }
