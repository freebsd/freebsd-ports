--- src/opl.c.orig	2013-09-07 23:56:16 UTC
+++ src/opl.c
@@ -145,6 +145,29 @@ static fltype decrelconst[4] = {
 	(fltype)(1/22.44608)
 };
 
+// per-chip variables
+Bitu chip_num;
+op_type op[MAXOPERATORS];
+
+Bits int_samplerate;
+	
+Bit8u status;
+Bit32u opl_index;
+#if defined(OPLTYPE_IS_OPL3)
+Bit8u adlibreg[512];	// adlib register set (including second set)
+Bit8u wave_sel[44];		// waveform selection
+#else
+Bit8u adlibreg[256];	// adlib register set
+Bit8u wave_sel[22];		// waveform selection
+#endif
+
+
+// vibrato/tremolo increment/counter
+Bit32u vibtab_pos;
+Bit32u vibtab_add;
+Bit32u tremtab_pos;
+Bit32u tremtab_add;
+
 
 void operator_advance(op_type* op_pt, Bit32s vib) {
 	op_pt->wfpos = op_pt->tcount;						// waveform position
