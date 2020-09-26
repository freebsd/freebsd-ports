--- src/opl.h.orig	2013-09-07 23:56:16 UTC
+++ src/opl.h
@@ -149,27 +149,27 @@ typedef struct operator_struct {
 } op_type;
 
 // per-chip variables
-Bitu chip_num;
-op_type op[MAXOPERATORS];
+extern Bitu chip_num;
+extern op_type op[MAXOPERATORS];
 
-Bits int_samplerate;
+extern Bits int_samplerate;
 	
-Bit8u status;
-Bit32u opl_index;
+extern Bit8u status;
+extern Bit32u opl_index;
 #if defined(OPLTYPE_IS_OPL3)
-Bit8u adlibreg[512];	// adlib register set (including second set)
-Bit8u wave_sel[44];		// waveform selection
+extern Bit8u adlibreg[512];	// adlib register set (including second set)
+extern Bit8u wave_sel[44];		// waveform selection
 #else
-Bit8u adlibreg[256];	// adlib register set
-Bit8u wave_sel[22];		// waveform selection
+extern Bit8u adlibreg[256];	// adlib register set
+extern Bit8u wave_sel[22];		// waveform selection
 #endif
 
 
 // vibrato/tremolo increment/counter
-Bit32u vibtab_pos;
-Bit32u vibtab_add;
-Bit32u tremtab_pos;
-Bit32u tremtab_add;
+extern Bit32u vibtab_pos;
+extern Bit32u vibtab_add;
+extern Bit32u tremtab_pos;
+extern Bit32u tremtab_add;
 
 
 // enable an operator
