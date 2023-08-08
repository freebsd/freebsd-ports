From 6a573e4b8333ee63ee62ce95558c3667348db233 Mon Sep 17 00:00:00 2001
From: Glen Fernandes <glen.fernandes@gmail.com>
Date: Mon, 17 Apr 2023 06:59:02 -0400
Subject: [PATCH] Define unary_function and binary_function unconditionally

--- boost/functional.hpp.orig	2023-04-10 13:47:33 UTC
+++ boost/functional.hpp
@@ -21,7 +21,6 @@ namespace boost
     namespace functional
     {
         namespace detail {
-#if defined(_HAS_AUTO_PTR_ETC) && !_HAS_AUTO_PTR_ETC
             // std::unary_function and std::binary_function were both removed
             // in C++17.
 
@@ -39,12 +38,6 @@ namespace boost
                 typedef Arg2 second_argument_type;
                 typedef Result result_type;
             };
-#else
-            // Use the standard objects when we have them.
-
-            using std::unary_function;
-            using std::binary_function;
-#endif
         }
     }
 
