$NetBSD: patch-libbase_accumulator.h,v 1.1 2015/09/23 12:00:53 joerg Exp $

--- libbase/accumulator.h.orig	2015-09-17 11:20:41.000000000 +0000
+++ libbase/accumulator.h
@@ -60,6 +60,7 @@ public:
     /// There are no tokens for an accumulator_type
     virtual unsigned min_tokens() const { return 0; }
     virtual unsigned max_tokens() const { return 0; }
+    virtual bool adjacent_tokens_only() const { return true; }
 
     /// Accumulating from different sources is silly.
     virtual bool is_composing() const { return false; }
