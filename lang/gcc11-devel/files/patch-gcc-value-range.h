From: Aldy Hernandez <aldyh@redhat.com>
To: Martin Liška <mliska@suse.cz>, Gerald Pfeifer <gerald@pfeifer.com>
Cc: gcc-patches@gcc.gnu.org
Date: Mon, 10 Aug 2020 09:44:17 +0200
Subject: Re: [patch] multi-range implementation for value_range (irange)

:

gcc/ChangeLog:

	* value-range.h (gt_ggc_mx): Declare inline.
	(gt_pch_nx): Same.
---
  gcc/value-range.h | 6 +++---
  1 file changed, 3 insertions(+), 3 deletions(-)

diff --git a/gcc/value-range.h b/gcc/value-range.h
index e3282c4ad03..1ab39939703 100644
--- gcc/value-range.h
+++ gcc/value-range.h
@@ -343,7 +343,7 @@
 }
 
 template<unsigned N>
-static inline void
+inline void
 gt_ggc_mx (int_range<N> *x)
 {
   for (unsigned i = 0; i < N; ++i)
@@ -354,7 +354,7 @@
 }
 
 template<unsigned N>
-static inline void
+inline void
 gt_pch_nx (int_range<N> *x)
 {
   for (unsigned i = 0; i < N; ++i)
@@ -365,7 +365,7 @@
 }
 
 template<unsigned N>
-static inline void
+inline void
 gt_pch_nx (int_range<N> *x, gt_pointer_operator op, void *cookie)
 {
   for (unsigned i = 0; i < N; ++i)
