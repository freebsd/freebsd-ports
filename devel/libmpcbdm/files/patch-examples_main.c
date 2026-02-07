--- example/main.c.orig	Sat Jun 24 13:15:08 2006
+++ example/main.c	Sat Jun 24 13:15:44 2006
@@ -50,7 +50,8 @@
 		power_on = atoi( argv[3] );
 
 	mpc8xx_set_print_function( print );
-	mpc8xx_bdm_init( lpt_port, adapter_version, power_on );
+	if (mpc8xx_bdm_init( lpt_port, adapter_version, power_on ) == -1)
+		exit(1);
 
 	mpc8xx_bdm_reset();
 
