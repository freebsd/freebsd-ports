--- boost/interprocess/shared_memory_object.hpp.orig	2012-07-12 15:27:30.607506166 +0200
+++ boost/interprocess/shared_memory_object.hpp	2012-07-12 15:30:22.481507868 +0200
@@ -1,6 +1,6 @@
 //////////////////////////////////////////////////////////////////////////////
 //
-// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
+// (C) Copyright Ion Gaztanaga 2005-2011. Distributed under the Boost
 // Software License, Version 1.0. (See accompanying file
 // LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 //
@@ -251,7 +251,7 @@
 
 #if defined(__FreeBSD__)
 
-inline bool use_filesistem_based_posix()
+inline bool use_filesystem_based_posix()
 {
    int jailed = 0;
    std::size_t len = sizeof(jailed);
@@ -275,7 +275,7 @@
    #if defined(BOOST_INTERPROCESS_FILESYSTEM_BASED_POSIX_SHARED_MEMORY)
    const bool add_leading_slash = false;
    #elif defined(BOOST_INTERPROCESS_RUNTIME_FILESYSTEM_BASED_POSIX_SHARED_MEMORY)
-   const bool add_leading_slash = !shared_memory_object_ipcdetail::use_filesistem_based_posix();
+   const bool add_leading_slash = !shared_memory_object_detail::use_filesystem_based_posix();
    #else
    const bool add_leading_slash = true;
    #endif
@@ -361,7 +361,7 @@
       #if defined(BOOST_INTERPROCESS_FILESYSTEM_BASED_POSIX_SHARED_MEMORY)
       const bool add_leading_slash = false;
       #elif defined(BOOST_INTERPROCESS_RUNTIME_FILESYSTEM_BASED_POSIX_SHARED_MEMORY)
-      const bool add_leading_slash = !shared_memory_object_ipcdetail::use_filesistem_based_posix();
+      const bool add_leading_slash = !shared_memory_object_detail::use_filesystem_based_posix();
       #else
       const bool add_leading_slash = true;
       #endif