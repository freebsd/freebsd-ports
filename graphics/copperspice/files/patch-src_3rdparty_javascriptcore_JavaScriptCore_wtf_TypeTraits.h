--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/TypeTraits.h.orig	2015-04-23 19:00:28 UTC
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/TypeTraits.h
@@ -164,60 +164,15 @@ namespace WTF {
         typedef T Type;
     };
 
+    template<typename T>
+    struct HasTrivialConstructor :
+        public std::is_trivially_constructible<T> {
+    };
 
-} // namespace WTF
-
-
-// copperspice solution for type traits (used in javascript and webkit)
-class cs_alternate{};
-
-class cs_preferred : public cs_alternate{};
-
-namespace std{
-   template<class> struct is_trivially_constructible;
-   template<class> struct has_trivial_default_constructor;
-  
-   template<class> struct is_trivially_destructible; 
-   template<class> struct has_trivial_destructor;  
-}
-
-namespace WTF {
-
-// constructor
-template<typename T>
-decltype(std::is_trivially_constructible<T>::value, std::is_trivially_constructible<T>{}) 
-   cs_check_constructor(const cs_preferred &)
-{
-}
-
-template<typename T>
-decltype(std::has_trivial_default_constructor<T>::value, std::has_trivial_default_constructor<T>{}) 
-   cs_check_constructor(const cs_alternate &)
-{
-}
-
-template<typename T> 
-struct HasTrivialConstructor : public decltype(cs_check_constructor<T>(cs_preferred{}))
-{
-};
-
-// destructor
-template<typename T>
-decltype(std::is_trivially_destructible<T>::value, std::is_trivially_destructible<T>{}) 
-   cs_check_destructor(const cs_preferred &)
-{
-}
-
-template<typename T>
-decltype(std::has_trivial_destructor<T>::value, std::has_trivial_destructor<T>{}) 
-   cs_check_destructor(const cs_alternate &)
-{
-}
-
-template<typename T>
-struct HasTrivialDestructor : public decltype(cs_check_destructor<T>(cs_preferred{}))
-{
-};
+    template<typename T>
+    struct HasTrivialDestructor :
+        public std::is_trivially_destructible<T> {
+    };
 
 } // namespace WTF
 
