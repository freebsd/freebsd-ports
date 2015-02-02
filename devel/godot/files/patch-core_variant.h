--- core/variant.h.orig	2014-12-15 18:49:18 UTC
+++ core/variant.h
@@ -167,8 +167,9 @@ public:
 	static String get_type_name(Variant::Type p_type);
 	static bool can_convert(Type p_type_from,Type p_type_to);
 
+#if defined(_MSC_VER)
 #pragma runtime_checks( "", off )
-
+#endif
 	template<class T>
 	static Type get_type_for() {
 		
@@ -177,8 +178,9 @@ public:
 		Type r = v.get_type();
 		return r;
 	}
+#if defined(_MSC_VER)
 #pragma runtime_checks( "", restore )
-
+#endif
 	bool is_ref() const;
 	_FORCE_INLINE_ bool is_num() const { return type==INT || type==REAL; };
 	_FORCE_INLINE_ bool is_array() const { return type>=ARRAY; };
