--- NOVA/nova_cpu.c.orig	2016-12-01 22:43:42 UTC
+++ NOVA/nova_cpu.c
@@ -243,11 +243,12 @@
 #define STK_CHECK(x,y)  if (((x) & 0377) < (y)) \
                             int_req = int_req | INT_STK
 #define IND_STEP(x)     M[x] & A_IND;  /* return next level indicator */ \
-                        if ( ((x) <= AUTO_TOP) && ((x) >= AUTO_INC) )    \
+                        if ( ((x) <= AUTO_TOP) && ((x) >= AUTO_INC) ) {   \
                             if ( (x) < AUTO_DEC )    \
                                 M[x] = (M[x] + 1) & DMASK;    \
                             else    \
                                 M[x] = (M[x] - 1) & DMASK;    \
+			    } \
                         x = M[x] & AMASK
 
 #define INCREMENT_PC    PC = (PC + 1) & AMASK           /* increment PC */
