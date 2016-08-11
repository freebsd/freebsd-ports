--- src/hal/drivers/hal_gm.c.orig	2016-06-25 02:19:12 UTC
+++ src/hal/drivers/hal_gm.c
@@ -1791,6 +1791,10 @@ stepgenControl(void *arg, long period, u
 	  }
   
 	}
+
+	else {
+		ref_vel = 90210; // XXX: 42 perhaps?
+	}
       //Check max velocity, max acceleration and output baudrate
       
 	//Check max velocity
