From ba27300d419786ca6fa8a7df950d01f472de3314 Mon Sep 17 00:00:00 2001
From: Tor Lillqvist <tml@collabora.com>
Date: Tue, 8 Jul 2014 09:49:50 +0300
Subject: Fix some round() confusion

Why insist on using the same name as a standard function? Causes
confusion with VS2013 at least, "ambiguous call to overloaded
function."

Sure, this might be caused by a bug in the compiler (or its
headers). Or maybe vagueness in the language definition? Who cares, I
still claim that intentionally writing an own function called round()
is asking for problems. So rename it to round_to_long().

(And then the return value of calls to this function, which is of type
'long', is assigned in a couple of places to variables of type 'int',
fun... Intentional, knowing there will be no overflow, or a bug
waiting to happen?)

Change-Id: If15d44f10f9f05de1c7c79492baf158eee770b8b

--- vcl/source/glyphs/graphite_layout.cxx.orig	2015-04-20 19:36:29 UTC
+++ vcl/source/glyphs/graphite_layout.cxx
@@ -40,6 +40,8 @@
 #include <deque>
 
 // Platform
+#include <config_global.h>
+
 #include <svsys.h>
 
 #include <salgdi.hxx>
@@ -86,7 +88,7 @@ static FILE * grLog()
 
 namespace
 {
-    inline long round(const float n) {
+    inline long round_to_long(const float n) {
         return long(n + (n < 0 ? -0.5 : 0.5));
     }
 
@@ -354,8 +356,8 @@ GraphiteLayout::fillFrom(gr_segment * pS
             baseSlot = gr_slot_next_sibling_attachment(baseSlot);
         }
     }
-    long nXOffset = round(fMinX * fScaling);
-    mnWidth = round(fMaxX * fScaling) - nXOffset + nDxOffset;
+    long nXOffset = round_to_long(fMinX * fScaling);
+    mnWidth = round_to_long(fMaxX * fScaling) - nXOffset + nDxOffset;
     if (mnWidth < 0)
     {
         // This can happen when there was no base inside the range
@@ -426,8 +428,8 @@ GraphiteLayout::append(gr_segment *pSeg,
         nextOrigin = nextGlyphOrigin;
     long glyphId = gr_slot_gid(gi);
     long deltaOffset = 0;
-    int scaledGlyphPos = round(gr_slot_origin_X(gi) * scaling);
-    int glyphWidth = round((nextOrigin - gOrigin) * scaling);
+    int scaledGlyphPos = round_to_long(gr_slot_origin_X(gi) * scaling);
+    int glyphWidth = round_to_long((nextOrigin - gOrigin) * scaling);
 //    if (glyphWidth < 0)
 //    {
 //        nextOrigin = gOrigin;
@@ -469,11 +471,11 @@ GraphiteLayout::append(gr_segment *pSeg,
     GlyphItem aGlyphItem(mvGlyphs.size(),
         glyphId,
         Point(scaledGlyphPos + rDXOffset,
-            round((-gr_slot_origin_Y(gi) * scaling))),
+            round_to_long((-gr_slot_origin_Y(gi) * scaling))),
         nGlyphFlags,
         glyphWidth);
     if (glyphId != static_cast<long>(GF_DROPPED))
-        aGlyphItem.mnOrigWidth = round(gr_slot_advance_X(gi, mpFace, mpFont) * scaling);
+        aGlyphItem.mnOrigWidth = round_to_long(gr_slot_advance_X(gi, mpFace, mpFont) * scaling);
     mvGlyphs.push_back(aGlyphItem);
 
     // update the offset if this glyph was dropped
