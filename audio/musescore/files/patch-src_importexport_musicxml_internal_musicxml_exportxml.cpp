--- src/importexport/musicxml/internal/musicxml/exportxml.cpp.orig	2024-02-05 22:14:10 UTC
+++ src/importexport/musicxml/internal/musicxml/exportxml.cpp
@@ -3624,8 +3624,8 @@ static void writeBeam(XmlWriter& xml, ChordRest* const
         // TODO: correctly handle Beam::Mode::AUTO
         // when equivalent to BEGIN32 or BEGIN64
         if ((blp < i && bln >= i)
-            || bmc == BeamMode::BEGIN16 && i > 1
-            || bmc == BeamMode::BEGIN32 && i > 2) {
+            || (bmc == BeamMode::BEGIN16 && i > 1)
+            || (bmc == BeamMode::BEGIN32 && i > 2)) {
             text = "begin";
         } else if (blp < i && bln < i) {
             if (bln > 0) {
@@ -3634,8 +3634,8 @@ static void writeBeam(XmlWriter& xml, ChordRest* const
                 text = "backward hook";
             }
         } else if ((blp >= i && bln < i)
-                   || bmn == BeamMode::BEGIN16 && i > 1
-                   || bmn == BeamMode::BEGIN32 && i > 2) {
+                   || (bmn == BeamMode::BEGIN16 && i > 1)
+                   || (bmn == BeamMode::BEGIN32 && i > 2)) {
             text = "end";
         } else if (blp >= i && bln >= i) {
             text = "continue";
