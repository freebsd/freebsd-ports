From 48d686f9718f98122547a9006c871cfcd50439ab Mon Sep 17 00:00:00 2001
From: Douglas Katzman <dougk@google.com>
Date: Sun, 31 Jul 2022 21:38:19 -0400
Subject: [PATCH] Accept that value-cell-value can move to R/O space

Fixes lp#1983218
--- src/runtime/stringspace.c.orig	2022-07-29 14:39:18 UTC
+++ src/runtime/stringspace.c
@@ -76,6 +76,7 @@ static void visit_pointer_words(lispobj* object, lispo
                widetag == RATIO_WIDETAG || widetag == COMPLEX_WIDETAG ||
                widetag == SIMPLE_ARRAY_WIDETAG ||
                (widetag >= COMPLEX_BASE_STRING_WIDETAG && widetag <= COMPLEX_ARRAY_WIDETAG) ||
+               widetag == VALUE_CELL_WIDETAG ||
                widetag == WEAK_POINTER_WIDETAG) {
         int len = object_size(object), i;
         for (i=1; i<len; ++i) FIX(object[i]);
