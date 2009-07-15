--- ./freebsd.c.orig	2008-04-26 04:19:38.000000000 -0400
+++ ./freebsd.c	2009-07-15 12:05:10.789747000 -0400
@@ -4,9 +4,9 @@
 
 /* 
 * File:    freebsd.c
-* CVS:     $Id: freebsd.c,v 1.1 2008-04-26 08:19:38 servat Exp $
+* CVS:     $Id: freebsd.c,v 1.6 2009/07/09 13:02:25 servat Exp $
 * Author:  Harald Servat
-*          harald.servat@gmail.com
+*          redcrash@gmail.com
 */
 
 #include <sys/types.h>
@@ -147,6 +147,14 @@
 		Context.CPUsubstrate = CPU_K8;
 	else if (strcmp(pmc_name_of_cputype(info->pm_cputype), "INTEL_PIV") == 0)
 		Context.CPUsubstrate = CPU_P4;
+	else if (strcmp(pmc_name_of_cputype(info->pm_cputype), "INTEL_ATOM") == 0)
+		Context.CPUsubstrate = CPU_ATOM;
+	else if (strcmp(pmc_name_of_cputype(info->pm_cputype), "INTEL_CORE") == 0)
+		Context.CPUsubstrate = CPU_CORE;
+	else if (strcmp(pmc_name_of_cputype(info->pm_cputype), "INTEL_CORE2") == 0)
+		Context.CPUsubstrate = CPU_CORE2;
+	else if (strcmp(pmc_name_of_cputype(info->pm_cputype), "INTEL_CORE2EXTREME") == 0)
+		Context.CPUsubstrate = CPU_CORE2EXTREME;
 	else
 		/* Unknown processor! */
 		Context.CPUsubstrate = CPU_UNKNOWN;
@@ -168,14 +176,11 @@
  */
 int init_mdi(void)
 {
-	int result;
 	const struct pmc_cpuinfo *info;
    
 	SHOW_WHERE_I_AM;
 
 	/* Initialize PMC library */
-	result = pmc_init();
-
 	if (pmc_init() < 0)
 		return PAPI_ESYS;
       
@@ -187,7 +192,7 @@
 		/* Get CPU clock rate from HW.CLOCKRATE sysctl value, and
 		   MODEL from HW.MODEL */
 		int mib[5];
-		unsigned len;
+		size_t len;
 		int hw_clockrate;
 		char hw_model[PAPI_MAX_STR_LEN];
      
