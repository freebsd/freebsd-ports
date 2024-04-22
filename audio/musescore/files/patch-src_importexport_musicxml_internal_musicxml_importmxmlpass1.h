--- src/importexport/musicxml/internal/musicxml/importmxmlpass1.h.orig	2024-02-05 22:17:12 UTC
+++ src/importexport/musicxml/internal/musicxml/importmxmlpass1.h
@@ -179,7 +179,7 @@ class MusicXMLParserPass1 (public)
     bool hasBeamingInfo() const { return _hasBeamingInfo; }
     bool isVocalStaff(const QString& id) const { return _parts[id].isVocalStaff(); }
     static VBox* createAndAddVBoxForCreditWords(Score* const score, const int miny = 0, const int maxy = 75);
-    const int maxDiff() { return _maxDiff; }
+    int maxDiff() const { return _maxDiff; }
     void insertAdjustedDuration(Fraction key, Fraction value) { _adjustedDurations.insert(key, value); }
     QMap<Fraction, Fraction>& adjustedDurations() { return _adjustedDurations; }
     void insertSeenDenominator(int val) { _seenDenominators.emplace(val); }
