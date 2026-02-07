--- src/synfig/rendering/software/function/array.h.orig	2025-04-14 18:37:34 UTC
+++ src/synfig/rendering/software/function/array.h
@@ -426,7 +426,7 @@
 	};
 
 	void fill(const Type &x) const
-		{ for(Iterator i(*this); i; ++i) i.get_array().template fill(x); }
+		{ for(Iterator i(*this); i; ++i) i.get_array().template fill<Type>(x); }
 
 	template<typename TT>
 	void assign(const Array<TT, Rank> &x) const
