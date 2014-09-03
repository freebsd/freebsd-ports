--- utils/profile/symbol.h.orig
+++ utils/profile/symbol.h
@@ -73,6 +73,7 @@
 ARMword ARMul_TaskCreate(ARMul_State *state);
 void ARMul_ReportEnergy(ARMul_State *state, FILE* pf);
 void ARMul_Consolidate(ARMul_State *state);
+char *get_sym(ARMword address);
 
 #endif
 #endif
