--- freebsd.c	2008-04-26 10:19:38.000000000 +0200
+++ freebsd.new.c	2009-03-21 18:54:19.000000000 +0100
@@ -174,8 +174,6 @@
 	SHOW_WHERE_I_AM;
 
 	/* Initialize PMC library */
-	result = pmc_init();
-
 	if (pmc_init() < 0)
 		return PAPI_ESYS;
       
@@ -187,7 +185,7 @@
 		/* Get CPU clock rate from HW.CLOCKRATE sysctl value, and
 		   MODEL from HW.MODEL */
 		int mib[5];
-		unsigned len;
+		size_t len;
 		int hw_clockrate;
 		char hw_model[PAPI_MAX_STR_LEN];
      
