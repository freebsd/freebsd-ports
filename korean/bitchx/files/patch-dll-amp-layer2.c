--- dll/amp/layer2.c.orig	Mon Oct  4 09:45:52 1999
+++ dll/amp/layer2.c	Fri Aug  5 19:23:35 2005
@@ -78,6 +78,7 @@
 					   sblimit=8;
 					   break;
 				default  : /*printf(" bit alloc info no gud ");*/
+					   ;
 				}
 				break;
 		case 1 : switch (bitrate)	/* 1 = 48 kHz */
@@ -99,6 +100,7 @@
 					   sblimit=8;
 					   break;
 				default  : /*printf(" bit alloc info no gud ");*/
+					   ;
 				}
 				break;
 		case 2 : switch (bitrate)	/* 2 = 32 kHz */
@@ -123,9 +125,11 @@
                                    sblimit=12;
 				   break;
 			default  : /*printf("bit alloc info not ok\n");*/
+					   ;
 			}
 	                break;                                                    
 		default  : /*printf("sampling freq. not ok/n");*/
+					   ;
 	} else {
 		bit_alloc_index=&t_allocMPG2;
 		nbal=&t_nbalMPG2;
