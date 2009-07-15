--- ./freebsd.h.orig	2008-04-26 04:19:38.000000000 -0400
+++ ./freebsd.h	2009-07-15 12:05:10.807711000 -0400
@@ -3,11 +3,11 @@
 /****************************/
 /* 
 * File:    freebsd-libpmc.c
-* CVS:     $Id: freebsd.h,v 1.1 2008-04-26 08:19:38 servat Exp $
+* CVS:     $Id: freebsd.h,v 1.3 2009/07/09 13:02:25 servat Exp $
 * Author:  Kevin London
 *          london@cs.utk.edu
 * Mods:    Harald Servat
-*          harald.servat@gmail.com
+*          redcrash@gmail.com
 */
 
 #ifndef _PAPI_FreeBSD_H
@@ -51,7 +51,7 @@
 	int hwc_domain;      /* HWC domain {user|kernel} */
 	unsigned *caps;      /* Capabilities for each counter */
 	pmc_id_t *pmcs;      /* PMC identifiers */
-	long_long *values;   /* Stored values for each counter */
+	long long *values;   /* Stored values for each counter */
 	char **counters;     /* Name of each counter (with mode) */
 } hwd_control_state_t;
 
