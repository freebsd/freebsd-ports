--- src/SNESAPU/SPC700.Inc.orig	2008-04-17 15:36:56.859375762 -0400
+++ src/SNESAPU/SPC700.Inc	2008-04-17 15:37:23.564907331 -0400
@@ -119,7 +119,7 @@
 	rY			resb	1
 	rX			resb	1
 	rPSW		resb	1
-	rSP		resw	1
+	rSP_nr		resw	1
 
 	tmr8kHz	resd	1									;[1.0] # of cycles left until timer increase
 	tmr64kHz	resd	1
