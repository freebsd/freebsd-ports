--- cpu/fetchdecode.cc.orig	Wed Jan 22 07:18:30 2003
+++ cpu/fetchdecode.cc	Sun Jul 13 10:09:27 2003
@@ -160,53 +160,53 @@
 } BxOpcodeInfo_t;
 
 static BxOpcodeInfo_t opcodesADD_EwIw[2] = {
-  { 0,  { &BX_CPU_C::ADD_EEwIw } },
-  { 0,  { &BX_CPU_C::ADD_EGwIw } }
+  { 0, &BX_CPU_C::ADD_EEwIw },
+  { 0, &BX_CPU_C::ADD_EGwIw }
   };
 
 static BxOpcodeInfo_t opcodesADD_EdId[2] = {
-  { 0,  { &BX_CPU_C::ADD_EEdId } },
-  { 0,  { &BX_CPU_C::ADD_EGdId } }
+  { 0, &BX_CPU_C::ADD_EEdId },
+  { 0, &BX_CPU_C::ADD_EGdId }
   };
 
 static BxOpcodeInfo_t opcodesADD_GwEw[2] = {
-  { 0,  { &BX_CPU_C::ADD_GwEEw } },
-  { 0,  { &BX_CPU_C::ADD_GwEGw } }
+  { 0, &BX_CPU_C::ADD_GwEEw },
+  { 0, &BX_CPU_C::ADD_GwEGw }
   };
 
 static BxOpcodeInfo_t opcodesADD_GdEd[2] = {
-  { 0,  { &BX_CPU_C::ADD_GdEEd } },
-  { 0,  { &BX_CPU_C::ADD_GdEGd } }
+  { 0, &BX_CPU_C::ADD_GdEEd },
+  { 0, &BX_CPU_C::ADD_GdEGd }
   };
 
 static BxOpcodeInfo_t opcodesMOV_GbEb[2] = {
-  { 0,  { &BX_CPU_C::MOV_GbEEb } },
-  { 0,  { &BX_CPU_C::MOV_GbEGb } }
+  { 0, &BX_CPU_C::MOV_GbEEb },
+  { 0, &BX_CPU_C::MOV_GbEGb }
   };
 
 static BxOpcodeInfo_t opcodesMOV_GwEw[2] = {
-  { 0,  { &BX_CPU_C::MOV_GwEEw } },
-  { 0,  { &BX_CPU_C::MOV_GwEGw } }
+  { 0, &BX_CPU_C::MOV_GwEEw },
+  { 0, &BX_CPU_C::MOV_GwEGw }
   };
 
 static BxOpcodeInfo_t opcodesMOV_GdEd[2] = {
-  { 0,  { &BX_CPU_C::MOV_GdEEd } },
-  { 0,  { &BX_CPU_C::MOV_GdEGd } }
+  { 0, &BX_CPU_C::MOV_GdEEd },
+  { 0, &BX_CPU_C::MOV_GdEGd }
   };
 
 static BxOpcodeInfo_t opcodesMOV_EbGb[2] = {
-  { 0,  { &BX_CPU_C::MOV_EEbGb } },
-  { 0,  { &BX_CPU_C::MOV_EGbGb } }
+  { 0, &BX_CPU_C::MOV_EEbGb },
+  { 0, &BX_CPU_C::MOV_EGbGb }
   };
 
 static BxOpcodeInfo_t opcodesMOV_EwGw[2] = {
-  { 0,  { &BX_CPU_C::MOV_EEwGw } },
-  { 0,  { &BX_CPU_C::MOV_EGwGw } }
+  { 0, &BX_CPU_C::MOV_EEwGw },
+  { 0, &BX_CPU_C::MOV_EGwGw }
   };
 
 static BxOpcodeInfo_t opcodesMOV_EdGd[2] = {
-  { 0,  { &BX_CPU_C::MOV_EEdGd } },
-  { 0,  { &BX_CPU_C::MOV_EGdGd } }
+  { 0, &BX_CPU_C::MOV_EEdGd },
+  { 0, &BX_CPU_C::MOV_EGdGd }
   };
 
 /* ********** */
