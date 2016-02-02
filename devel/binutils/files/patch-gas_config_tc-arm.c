From d840c081f8082e8b9e63fead5306643975a97bb3 Mon Sep 17 00:00:00 2001
From: Richard Earnshaw <Richard.Earnshaw@arm.com>
Date: Thu, 20 Nov 2014 17:02:47 +0000
Subject: [PATCH] * config/tc-arm.c (rotate_left): Avoid undefined behaviour
 when N = 0.

--- gas/config/tc-arm.c.orig	2014-10-14 09:32:03.000000000 +0200
+++ gas/config/tc-arm.c	2015-02-18 21:13:40.720573000 +0100
@@ -7251,7 +7251,7 @@
 
 /* Functions for operand encoding.  ARM, then Thumb.  */
 
-#define rotate_left(v, n) (v << n | v >> (32 - n))
+#define rotate_left(v, n) (v << (n & 31) | v >> ((32 - n) & 31))
 
 /* If VAL can be encoded in the immediate field of an ARM instruction,
    return the encoded form.  Otherwise, return FAIL.  */
