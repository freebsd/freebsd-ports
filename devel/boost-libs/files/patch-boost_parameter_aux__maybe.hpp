--- boost/parameter/aux_/maybe.hpp.orig	2008-03-23 00:45:55.000000000 +0300
+++ boost/parameter/aux_/maybe.hpp	2009-12-22 14:56:01.000000000 +0300
@@ -2,20 +2,41 @@
 // subject to the Boost Software License, Version 1.0. (See accompanying
 // file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 
-#ifndef BOOST_PARAMETER_MAYBE_060211_HPP
-# define BOOST_PARAMETER_MAYBE_060211_HPP
+//
+// 2009.10.21 TDS remove depenency on boost::python::detail::referent_storage
+//
+#ifndef BOOST_PARAMETER_MAYBE_091021_HPP
+# define BOOST_PARAMETER_MAYBE_091021_HPP
 
 # include <boost/mpl/if.hpp>
 # include <boost/mpl/identity.hpp>
 # include <boost/type_traits/is_reference.hpp>
 # include <boost/type_traits/add_reference.hpp>
 # include <boost/optional.hpp>
-# include <boost/python/detail/referent_storage.hpp>
+# include <boost/aligned_storage.hpp>
 # include <boost/type_traits/remove_cv.hpp>
 # include <boost/type_traits/add_const.hpp>
 
 namespace boost { namespace parameter { namespace aux {
 
+template <class T> struct referent_size;
+
+template <class T>
+struct referent_size<T&>
+{
+  BOOST_STATIC_CONSTANT(std::size_t, value = sizeof(T));
+};
+
+// A metafunction returning a POD type which can store U, where T ==
+// U&. If T is not a reference type, returns a POD which can store T.
+template <class T>
+struct referent_storage
+{
+  typedef typename boost::aligned_storage<
+    referent_size<T>::value
+    >::type type;
+};
+
 struct maybe_base {};
 
 template <class T>
@@ -56,9 +77,9 @@
     template <class U>
     reference construct2(U const& value) const
     {
-        new (m_storage.bytes) non_cv_value(value);
+        new (m_storage.address()) non_cv_value(value);
         constructed = true;
-        return *(non_cv_value*)m_storage.bytes;
+        return *(non_cv_value*)m_storage.address();
     }
 
     template <class U>
@@ -69,7 +90,7 @@
 
     void destroy()
     {
-        ((non_cv_value*)m_storage.bytes)->~non_cv_value();
+        ((non_cv_value*)m_storage.address())->~non_cv_value();
     }
 
     typedef reference(maybe<T>::*safe_bool)() const;
@@ -87,7 +108,8 @@
 private:
     boost::optional<T> value;
     mutable bool constructed;
-    mutable typename boost::python::detail::referent_storage<
+    
+    mutable typename referent_storage<
         reference
     >::type m_storage;
 };
