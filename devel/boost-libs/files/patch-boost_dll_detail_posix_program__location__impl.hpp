From d662bcbb67ae5da919d35f83e0bcc21769de0ac4 Mon Sep 17 00:00:00 2001
From: Antony Polukhin <antoshkka@gmail.com>
Date: Wed, 11 Jun 2025 09:59:25 +0300
Subject: [PATCH] Fix usage of missing variable (#98)

Fixes https://github.com/boostorg/dll/issues/96
--- boost/dll/detail/posix/program_location_impl.hpp.orig	2025-04-03 11:37:24 UTC
+++ boost/dll/detail/posix/program_location_impl.hpp
@@ -70,9 +70,10 @@ namespace boost { namespace dll { namespace detail {
         mib[2] = KERN_PROC_PATHNAME;
         mib[3] = -1;
         char path[1024];
-        size_t size = sizeof(buf);
-        if (sysctl(mib, 4, path, &size, nullptr, 0) == 0)
+        size_t size = sizeof(path);
+        if (sysctl(mib, 4, path, &size, nullptr, 0) == 0) {
             return boost::dll::fs::path(path);
+        }
 
         const auto errno_snapshot = static_cast<std::errc>(errno);
         if (errno_snapshot != std::errc::not_enough_memory) {
@@ -83,7 +84,7 @@ namespace boost { namespace dll { namespace detail {
 
         std::string p;
         p.resize(size);
-        if (sysctl(mib, 4, p.data(), &size, nullptr, 0) != 0) {
+        if (sysctl(mib, 4, &p[0], &size, nullptr, 0) != 0) {
             ec = std::make_error_code(
                 static_cast<std::errc>(errno)
             );
