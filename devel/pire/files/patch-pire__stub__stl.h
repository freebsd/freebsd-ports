--- pire/stub/stl.h.orig	2013-11-08 17:46:23 UTC
+++ pire/stub/stl.h
@@ -97,7 +97,7 @@ namespace Pire {
 		ylist(Arg1 arg1, Arg2 arg2, Arg3 arg3): std::list<T, A>(arg1, arg2, arg3) {}
 	};
 
-	template< class K, class V, class C = std::less<K>, class A = std::allocator< std::pair<K, V> > >
+	template< class K, class V, class C = std::less<K>, class A = std::allocator< std::pair<const K, V> > >
 	class ymap: public std::map<K, V, C, A> {
 	public:
 		ymap(): std::map<K, V, C, A>() {}
