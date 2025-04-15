From 87f42aa0e0096e9a346c9672aa3a0bd3bef8c1dd Mon Sep 17 00:00:00 2001
From: Karl Williamson <khw@cpan.org>
Date: Wed, 18 Dec 2024 18:25:29 -0700
Subject: [PATCH] CVE-2024-56406: Heap-buffer-overflow with tr//

This was due to underallocating needed space.  If the translation forces
something to become UTF-8 that is initially bytes, that UTF-8 could
now require two bytes where previously a single one would do.

(cherry picked from commit f93109c8a6950aafbd7488d98e112552033a3686)
--- op.c.orig	2023-11-28 11:57:24 UTC
+++ op.c
@@ -7605,6 +7605,7 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
                  * same time.  But otherwise one crosses before the other */
                 if (t_cp < 256 && r_cp_end > 255 && r_cp != t_cp) {
                     can_force_utf8 = TRUE;
+                    max_expansion = MAX(2, max_expansion);
                 }
             }
 
