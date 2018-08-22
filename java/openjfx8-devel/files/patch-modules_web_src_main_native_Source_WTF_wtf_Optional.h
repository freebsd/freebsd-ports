--- modules/web/src/main/native/Source/WTF/wtf/Optional.h.orig	2018-03-23 23:53:57 UTC
+++ modules/web/src/main/native/Source/WTF/wtf/Optional.h
@@ -295,12 +295,14 @@ struct nullopt_t
 constexpr nullopt_t nullopt{nullopt_t::init()};
 
 
+# if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION < 7000
 // 20.5.8, class bad_optional_access
 class bad_optional_access : public std::logic_error {
 public:
   explicit bad_optional_access(const std::string& what_arg) : std::logic_error{what_arg} {}
   explicit bad_optional_access(const char* what_arg) : std::logic_error{what_arg} {}
 };
+# endif // _LIBCPP_VERSION < 7000
 
 
 template <class T>
