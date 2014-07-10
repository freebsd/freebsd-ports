--- firmware/fx2/usrp1/gpif.c.orig	2014-07-04 14:55:38.716872326 -0400
+++ firmware/fx2/usrp1/gpif.c	2014-07-05 19:13:33.863851247 -0400
@@ -156,7 +156,7 @@
 // END DO NOT EDIT                            
                                               
 // DO NOT EDIT ...                     
-const char xdata WaveData[128] =     
+const char WaveData[128] =     
 {                                      
 // Wave 0 
 /* LenBr */ 0x01,     0x01,     0x01,     0x01,     0x01,     0x01,     0x01,     0x07,
@@ -182,7 +182,7 @@
 // END DO NOT EDIT     
                        
 // DO NOT EDIT ...                     
-const char xdata FlowStates[36] =   
+const char __xdata FlowStates[36] =   
 {                                      
 /* Wave 0 FlowStates */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 /* Wave 1 FlowStates */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
@@ -192,7 +192,7 @@
 // END DO NOT EDIT     
                        
 // DO NOT EDIT ...                                               
-const char xdata InitData[7] =                                   
+const char InitData[7] =                                   
 {                                                                
 /* Regs  */ 0xA0,0x00,0x00,0x00,0xEE,0x4E,0x00     
 };                                                               
