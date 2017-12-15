From c4c48e974013a1a3d62ae6b2fc9a705c3bdd1689 Mon Sep 17 00:00:00 2001
From: Sergei Golubchik <serg@mariadb.org>
Date: Tue, 7 Mar 2017 19:21:42 +0100
Subject: [PATCH] MDEV-11965 -Werror should not appear in released tarballs

---
 storage/tokudb/PerconaFT/cmake_modules/TokuSetupCompiler.cmake | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

diff --git a/storage/tokudb/PerconaFT/cmake_modules/TokuSetupCompiler.cmake b/storage/tokudb/PerconaFT/cmake_modules/TokuSetupCompiler.cmake
index 769bdffa5d99..c17e119d1cdc 100644
--- storage/tokudb/PerconaFT/cmake_modules/TokuSetupCompiler.cmake.orig
+++ storage/tokudb/PerconaFT/cmake_modules/TokuSetupCompiler.cmake
@@ -196,9 +196,9 @@ if (NOT CMAKE_CXX_COMPILER_ID STREQUAL Clang)
   set_cflags_if_supported(-Wcast-align)
 endif ()
 
-## always want these
-set(CMAKE_C_FLAGS "-Wall -Werror ${CMAKE_C_FLAGS}")
-set(CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
+## always want these in debug builds
+set(CMAKE_C_FLAGS_DEBUG "-Wall -Werror ${CMAKE_C_FLAGS_DEBUG}")
+set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Werror ${CMAKE_CXX_FLAGS_DEBUG}")
 
 # pick language dialect
 set(CMAKE_C_FLAGS "-std=c99 ${CMAKE_C_FLAGS}")
