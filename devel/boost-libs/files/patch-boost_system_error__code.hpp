Boost.System built in C++ >= 17 doesn't support C++14 consumers with GCC 7.3

$ cat >a.cc
#include <boost/system/error_code.hpp>

int main()
{
  boost::system::error_code e;
  e.clear();
  return 0;
}

$ g++7 -std=gnu++98 -lboost_system a.cc
$ g++7 -std=gnu++03 -lboost_system a.cc
$ g++7 -std=gnu++11 -lboost_system a.cc
$ g++7 -std=gnu++17 -lboost_system a.cc
$ g++7 -std=gnu++14 -lboost_system a.cc
/tmp//cciZnzeq.o: In function `main':
a.cc:(.text+0x24): undefined reference to `boost::system::detail::system_category_instance'
/tmp//cciZnzeq.o: In function `boost::system::system_category()':
a.cc:(.text._ZN5boost6system15system_categoryEv[_ZN5boost6system15system_categoryEv]+0x5): undefined reference to `boost::system::detail::system_category_instance'
/tmp//cciZnzeq.o: In function `boost::system::generic_category()':
a.cc:(.text._ZN5boost6system16generic_categoryEv[_ZN5boost6system16generic_categoryEv]+0x5): undefined reference to `boost::system::detail::generic_category_instance'

--- boost/system/error_code.hpp.orig	2018-08-01 20:50:53 UTC
+++ boost/system/error_code.hpp
@@ -43,7 +43,7 @@
 # define BOOST_SYSTEM_HAS_CONSTEXPR
 #endif
 
-#if defined(__GNUC__) && (__GNUC__ == 7 && __GNUC_MINOR__ < 4) && __cplusplus >= 201700L
+#if defined(__GNUC__) && (__GNUC__ == 7 && __GNUC_MINOR__ < 4)
 // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=83835
 #  undef BOOST_SYSTEM_HAS_CONSTEXPR
 #endif
