--- mchip.c.orig	Wed Aug  2 01:15:04 2000
+++ mchip.c	Wed Aug 18 21:11:26 2004
@@ -174,7 +174,7 @@
 		sdelay(1);
 	}
 	if (debug) {
-		printf(__FUNCTION__ " timeout\n");
+		printf("mchip_wait_frame timeout\n");
 	}
 	return 0;
 }
@@ -377,7 +377,7 @@
 
 	delay1(MCHIP_HIC_CMD);
 
-	printf("continuous compressed capture started\n");
+	fprintf(stderr, "continuous compressed capture started\n");
 }
 
 /* read one compressed frame from the framebuffer */
@@ -390,7 +390,7 @@
 void mchip_subsample(int sub)
 {
 	if (debug) {
-		printf(__FUNCTION__ " sub=%d\n", sub);
+		printf("mchip_subsample sub=%d\n", sub);
 	}
 	subsample = sub;
 	mchip_set(MCHIP_MCC_R_SAMPLING, subsample);
@@ -399,7 +399,7 @@
 	mchip_set(MCHIP_MCC_B_XRANGE, mchip_hsize());
 	mchip_set(MCHIP_MCC_B_YRANGE, mchip_vsize());
 	if (debug) {
-		printf(__FUNCTION__ " done\n");
+		printf("mchip_subsample done\n");
 	}
 	delay2(MCHIP_HIC_STATUS, MCHIP_HIC_STATUS_IDLE);
 }
