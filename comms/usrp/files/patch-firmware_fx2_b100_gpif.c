--- firmware/fx2/b100/gpif.c.orig	2012-10-10 13:39:33.000000000 -0500
+++ firmware/fx2/b100/gpif.c	2012-10-10 13:39:56.000000000 -0500
@@ -156,7 +156,7 @@
 // END DO NOT EDIT                            
                                               
 // DO NOT EDIT ...                     
-const char xdata WaveData[128] =     
+const char __xdata WaveData[128] =     
 {                                      
 // Wave 0 
 /* LenBr */ 0x01,     0x01,     0x01,     0x01,     0x01,     0x01,     0x01,     0x07,
@@ -182,7 +182,7 @@
 // END DO NOT EDIT     
                        
 // DO NOT EDIT ...                     
-const char xdata FlowStates[36] =   
+const char __xdata FlowStates[36] =   
 {                                      
 /* Wave 0 FlowStates */ 0x81,0x2D,0x0E,0x00,0x00,0x04,0x03,0x02,0x00,
 /* Wave 1 FlowStates */ 0x81,0x2D,0x09,0x00,0x00,0x04,0x03,0x02,0x00,
@@ -192,7 +192,7 @@
 // END DO NOT EDIT     
                        
 // DO NOT EDIT ...                                               
-const char xdata InitData[7] =                                   
+const char __xdata InitData[7] =                                   
 {                                                                
 /* Regs  */ 0xA0,0x00,0x00,0x00,0xEE,0x4E,0x00     
 };                                                               
