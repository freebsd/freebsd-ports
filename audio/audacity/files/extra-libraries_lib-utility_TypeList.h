--- libraries/lib-utility/TypeList.h.orig	2023-11-16 11:58:21 UTC
+++ libraries/lib-utility/TypeList.h
@@ -54,6 +54,18 @@ namespace TypeList {
  can make compound predicates out of simpler ones.
   */
 
+template <class...>
+struct conjunction : std::true_type {};
+
+template <class _Arg>
+struct conjunction<_Arg> : _Arg {};
+
+template <class _Arg, class... _Args>
+struct conjunction<_Arg, _Args...> : std::conditional_t<!bool(_Arg::value), _Arg, conjunction<_Args...>> {};
+
+template <class _Bp, class _Dp>
+inline constexpr bool is_base_of_v = __is_base_of(_Bp, _Dp);
+
 //! standard in C++20; add a level of indirection to a type
 template<typename T> struct type_identity { using type = T; };
 
@@ -429,7 +441,7 @@ struct And<Predicate, Predicates...> { (private)
       static constexpr bool value = Is_v<And<Predicates...>, T>;
    };
 public:
-   template<typename T> using typemap = typename std::conjunction<
+   template<typename T> using typemap = typename TypeList::conjunction<
       typename Predicate::template typemap<T>, Rest<T>
    >;
 };
@@ -437,7 +449,7 @@ struct And<Predicate, Predicates...> { (private)
 //! Derived from the Predicate, applied to the first of the types (often boolean
 //! constant types), for which the value is false; or std::true_type
 template<typename Predicate, typename TypeList> struct Every
-   : Apply_t<std::conjunction, Map_t<Predicate, TypeList>> {};
+   : Apply_t<conjunction, Map_t<Predicate, TypeList>> {};
 //! The constant value in the corresponding type
 template<typename Predicate, typename TypeList> constexpr auto Every_v =
    Every<Predicate, TypeList>::value;
