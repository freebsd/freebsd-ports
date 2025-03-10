https://github.com/bisqwit/TinyDeflate/commit/68ced8bd5c819264e628d4f063500753b77f613d.patch

From 68ced8bd5c819264e628d4f063500753b77f613d Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Bernhard=20Rosenkr=C3=A4nzer?= <bero@lindev.ch>
Date: Fri, 9 Aug 2024 14:09:01 +0200
Subject: [PATCH] Fix build with clang >= 19.0

Clang >= 19.0 requires a template argument list after the template
keyword for CWG96 compliance, see
https://github.com/llvm/llvm-project/pull/80801
--- TinyDeflate/gunzip.hh.orig	2025-01-08 14:32:52 UTC
+++ TinyDeflate/gunzip.hh
@@ -1141,21 +1141,21 @@ namespace gunzip_ns
             //fprintf(stderr, "both track flag\n");
             SizeTracker<DeflateTrackBothSize> tracker;
             return tracker(Gunzip<code & Flag_NoTrackFlagMask>
-                (tracker.template ForwardInput(i), tracker.template ForwardOutput(o), tracker.template ForwardWindow(c), std::forward<B>(b)));
+                (tracker.template ForwardInput<I>(i), tracker.template ForwardOutput<O>(o), tracker.template ForwardWindow<C>(c), std::forward<B>(b)));
         }
         else if constexpr(code & Flag_TrackIn)
         {
             //fprintf(stderr, "in track flag\n");
             SizeTracker<DeflateTrackInSize> tracker;
             return tracker(Gunzip<code & Flag_NoTrackFlagMask>
-                (tracker.template ForwardInput(i),std::forward<O>(o),std::forward<C>(c),std::forward<B>(b)));
+                (tracker.template ForwardInput<I>(i),std::forward<O>(o),std::forward<C>(c),std::forward<B>(b)));
         }
         else if constexpr(code & Flag_TrackOut)
         {
             //fprintf(stderr, "out track flag\n");
             SizeTracker<DeflateTrackOutSize> tracker;
             return tracker(Gunzip<code & Flag_NoTrackFlagMask>
-                (std::forward<I>(i), tracker.template ForwardOutput(o), tracker.template ForwardWindow(c), std::forward<B>(b)));
+                (std::forward<I>(i), tracker.template ForwardOutput<O>(o), tracker.template ForwardWindow<C>(c), std::forward<B>(b)));
         }
         else
         {
