--- swtp6800/common/m6800.c.orig	2016-12-01 22:43:43 UTC
+++ swtp6800/common/m6800.c
@@ -316,7 +316,7 @@ int32 sim_instr (void)
     while (reason == 0) {               /* loop until halted */
 //    dump_regs1();
         if (sim_interval <= 0)          /* check clock queue */
-            if (reason = sim_process_event ()) 
+            if ((reason = sim_process_event ())) 
                 break;
             if (mem_fault) {            /* memory fault? */
                 mem_fault = 0;          /* reset fault flag */
@@ -1890,18 +1890,20 @@ int32 get_flag(int32 flg)
 
 void condevalVa(int32 op1, int32 op2)
 {
-    if (get_flag(CF))
+    if (get_flag(CF)) {
         COND_SET_FLAG_V(((op1 & 0x80) && (op2 & 0x80)) || (
-            (op1 & 0x80 == 0) && (op2 & 0x80 == 0)));
+            ((op1 & 0x80) == 0) && ((op2 & 0x80) == 0)));
+    } 
 }
 
 /* test and set V for subtraction */
 
 void condevalVs(int32 op1, int32 op2)
 {
-    if (get_flag(CF))
-        COND_SET_FLAG_V(((op1 & 0x80) && (op2 & 0x80 == 0)) || 
-            ((op1 & 0x80 == 0) && (op2 & 0x80)));
+    if (get_flag(CF)) {
+        COND_SET_FLAG_V(((op1 & 0x80) && ((op2 & 0x80) == 0)) || 
+            ((((op1 & 0x80) == 0)) && (op2 & 0x80)));
+    }
 }
 
 /* calls from the simulator */
