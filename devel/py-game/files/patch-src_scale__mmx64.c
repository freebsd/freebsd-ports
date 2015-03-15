# HG changeset patch
# User Rene Dudfield <renesd@gmail.com>
# Date 1343499364 -7200
# Node ID e296ada67fad8e01e017ed6ede554fabb1402d26
# Parent  d2c7ea7488013b87c483f4df0b5ca80bdc87e065
Fix for scale_mmx64.c with clang. Thanks Joshua Root.  Closes #94

diff --git a/src/scale_mmx64.c b/src/scale_mmx64.c
--- src/scale_mmx64.c.orig	2008-10-22 20:54:59 UTC
+++ src/scale_mmx64.c
@@ -425,7 +425,7 @@ filter_expand_X_MMX(Uint8 *srcpix, Uint8
              " movl             %5,      %%ecx;           "
              " pxor          %%mm0,      %%mm0;           "
              "1:                                          "
-             " movsxl         (%3),      %%rax;           " /* get xidx0[x] */
+             " movslq         (%3),      %%rax;           " /* get xidx0[x] */
              " add              $4,         %3;           "
              " movq           (%0),      %%mm1;           " /* load mult0 */
              " add              $8,         %0;           "
@@ -500,7 +500,7 @@ filter_expand_X_SSE(Uint8 *srcpix, Uint8
              " movl             %5,      %%ecx;           "
              " pxor          %%mm0,      %%mm0;           "
              "1:                                          "
-             " movsxl         (%3),      %%rax;           " /* get xidx0[x] */
+             " movslq         (%3),      %%rax;           " /* get xidx0[x] */
              " add              $4,         %3;           "
              " movq           (%0),      %%mm1;           " /* load mult0 */
              " add              $8,         %0;           "
