--- Src/SoundChips/OpenMsxYM2413.cpp.orig	2021-02-15 16:41:14 UTC
+++ Src/SoundChips/OpenMsxYM2413.cpp
@@ -304,7 +304,7 @@ static const byte lfo_am_table[LFO_AM_TAB_ELEMENTS] =
 };
 
 // LFO Phase Modulation table (verified on real YM2413)
-static const char lfo_pm_table[8 * 8] = 
+static const signed char lfo_pm_table[8 * 8] = 
 {
 	// FNUM2/FNUM = 0 00xxxxxx (0x0000)
 	0, 0, 0, 0, 0, 0, 0, 0,
