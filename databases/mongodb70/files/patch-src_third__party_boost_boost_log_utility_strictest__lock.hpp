--- src/third_party/boost/boost/log/utility/strictest_lock.hpp.orig	2026-02-10 20:02:45 UTC
+++ src/third_party/boost/boost/log/utility/strictest_lock.hpp
@@ -16,7 +16,7 @@
 #ifndef BOOST_LOG_UTILITY_STRICTEST_LOCK_HPP_INCLUDED_
 #define BOOST_LOG_UTILITY_STRICTEST_LOCK_HPP_INCLUDED_
 
-#include <boost/mpl/integral_c.hpp>
+#include <boost/type_traits/integral_constant.hpp>
 #include <boost/log/detail/config.hpp>
 #include <boost/log/detail/locks.hpp>
 #if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
@@ -67,49 +67,49 @@ template< typename MutexT >
 struct thread_access_mode_of;
 
 template< typename MutexT >
-struct thread_access_mode_of< no_lock< MutexT > > : mpl::integral_c< lock_access_mode, unlocked_access >
+struct thread_access_mode_of< no_lock< MutexT > > : boost::integral_constant< lock_access_mode, unlocked_access >
 {
 };
 
 #if !defined(BOOST_LOG_NO_THREADS)
 
 template< typename MutexT >
-struct thread_access_mode_of< lock_guard< MutexT > > : mpl::integral_c< lock_access_mode, exclusive_access >
+struct thread_access_mode_of< lock_guard< MutexT > > : boost::integral_constant< lock_access_mode, exclusive_access >
 {
 };
 
 template< typename MutexT >
-struct thread_access_mode_of< shared_lock_guard< MutexT > > : mpl::integral_c< lock_access_mode, shared_access >
+struct thread_access_mode_of< shared_lock_guard< MutexT > > : boost::integral_constant< lock_access_mode, shared_access >
 {
 };
 
 template< typename MutexT >
-struct thread_access_mode_of< unique_lock< MutexT > > : mpl::integral_c< lock_access_mode, exclusive_access >
+struct thread_access_mode_of< unique_lock< MutexT > > : boost::integral_constant< lock_access_mode, exclusive_access >
 {
 };
 
 template< typename MutexT >
-struct thread_access_mode_of< shared_lock< MutexT > > : mpl::integral_c< lock_access_mode, shared_access >
+struct thread_access_mode_of< shared_lock< MutexT > > : boost::integral_constant< lock_access_mode, shared_access >
 {
 };
 
 template< typename MutexT >
-struct thread_access_mode_of< upgrade_lock< MutexT > > : mpl::integral_c< lock_access_mode, shared_access >
+struct thread_access_mode_of< upgrade_lock< MutexT > > : boost::integral_constant< lock_access_mode, shared_access >
 {
 };
 
 template< typename MutexT >
-struct thread_access_mode_of< boost::log::aux::exclusive_lock_guard< MutexT > > : mpl::integral_c< lock_access_mode, exclusive_access >
+struct thread_access_mode_of< boost::log::aux::exclusive_lock_guard< MutexT > > : boost::integral_constant< lock_access_mode, exclusive_access >
 {
 };
 
 template< typename MutexT >
-struct thread_access_mode_of< boost::log::aux::shared_lock_guard< MutexT > > : mpl::integral_c< lock_access_mode, shared_access >
+struct thread_access_mode_of< boost::log::aux::shared_lock_guard< MutexT > > : boost::integral_constant< lock_access_mode, shared_access >
 {
 };
 
 template< typename MutexT1, typename MutexT2 >
-struct thread_access_mode_of< boost::log::aux::multiple_unique_lock2< MutexT1, MutexT2 > > : mpl::integral_c< lock_access_mode, exclusive_access >
+struct thread_access_mode_of< boost::log::aux::multiple_unique_lock2< MutexT1, MutexT2 > > : boost::integral_constant< lock_access_mode, exclusive_access >
 {
 };
 
