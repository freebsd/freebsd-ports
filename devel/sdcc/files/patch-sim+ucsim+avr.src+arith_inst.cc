--- sim/ucsim/avr.src/arith_inst.cc.orig	Wed Nov 17 17:05:26 2004
+++ sim/ucsim/avr.src/arith_inst.cc	Wed Nov 17 17:09:31 2004
@@ -51,7 +51,7 @@
   if (D & 0x80)
     D|= ~0xff;
   t_mem sreg= ram->get(SREG);
-  (signed)result= (signed)D-(signed)K;
+  result= (t_mem)((signed)D-(signed)K);
   res= result & 0xff;
   
   sreg= sreg & ~(BIT_H|BIT_S|BIT_V|BIT_N|BIT_C|BIT_Z);
@@ -101,7 +101,7 @@
   if (D & 0x80)
     D|= ~0xff;
   t_mem sreg= ram->get(SREG);
-  (signed)result= (signed)D-(signed)K-(sreg&BIT_C)?1:0;
+  result= (t_mem)((signed)D-(signed)K-(sreg&BIT_C)?1:0);
   res= result & 0xff;
   ram->write(d, res);
   
@@ -151,7 +151,7 @@
     K|= ~0xff;
   if (D & 0x80)
     D|= ~0xff;
-  (signed)result= (signed)D-(signed)K;
+  result= (t_mem)((signed)D-(signed)K);
   res= result & 0xff;
   ram->write(d, res);
   
@@ -237,7 +237,7 @@
   if (D & 0x80)
     D|= ~0xff;
   t_mem sreg= ram->get(SREG);
-  (signed)result= (signed)D-(signed)R-(sreg&BIT_C)?1:0;
+  result= (t_mem)((signed)D-(signed)R-(sreg&BIT_C)?1:0);
   res= result & 0xff;
   
   sreg= sreg & ~(BIT_H|BIT_S|BIT_V|BIT_N|BIT_C);
@@ -287,7 +287,7 @@
   if (D & 0x80)
     D|= ~0xff;
   t_mem sreg= ram->get(SREG);
-  (signed)result= (signed)D-(signed)R-(sreg&BIT_C)?1:0;
+  result= (t_mem)((signed)D-(signed)R-(sreg&BIT_C)?1:0);
   res= result & 0xff;
   ram->write(d, res);
   
@@ -389,7 +389,7 @@
     R|= ~0xff;
   if (D & 0x80)
     D|= ~0xff;
-  (signed)result= (signed)D-(signed)R;
+  result= (t_mem)((signed)D-(signed)R);
   res= result & 0xff;
   
   t_mem sreg= ram->get(SREG) & ~(BIT_H|BIT_S|BIT_V|BIT_N|BIT_Z|BIT_C);
@@ -438,7 +438,7 @@
     R|= ~0xff;
   if (D & 0x80)
     D|= ~0xff;
-  (signed)result= (signed)D-(signed)R;
+  result= (t_mem)((signed)D-(signed)R);
   res= result & 0xff;
   ram->write(d, res);
   
@@ -922,7 +922,7 @@
     K|= ~0x3f;
   if (D & 0x8000)
     D|= ~0xffff;
-  (signed)result= (signed)D-(signed)K;
+  result= (t_mem)((signed)D-(signed)K);
   res= result & 0xffff;
   t_mem resl= res&0xff, resh= (res>>8)&0xff;
   ram->write(dl+1, resh);
