Index: freebsd/map-i7.c
diff -u freebsd/map-i7.c:1.1.2.1 freebsd/map-i7.c:1.1.2.2
--- freebsd/map-i7.c:1.1.2.1	Sat Oct 31 06:16:53 2009
+++ freebsd/map-i7.c	Sat Mar  6 11:12:08 2010
@@ -4,7 +4,7 @@
 
 /* 
 * File:    map-i7.c
-* CVS:     $Id: map-i7.c,v 1.1.2.1 2009/10/31 10:16:53 servat Exp $
+* CVS:     $Id: map-i7.c,v 1.1.2.2 2010/03/06 16:12:08 servat Exp $
 * Author:  George Neville-Neil
 *          gnn@freebsd.org
 *          Harald Servat
@@ -327,6 +327,9 @@
 	{"SIMD_INT_64.PACKED_LOGICAL", "Counts number of SID integer 64 bit logical operations."},
 	{"SIMD_INT_64.PACKED_ARITH", "Counts number of SID integer 64 bit arithmetic operations."},
 	{"SIMD_INT_64.SHUFFLE_MOVE", "Counts number of SID integer 64 bit shift or move operations."},
+	{"INSTR_RETIRED_ANY", "Instructions retired (IAF)"},
+	{"CPU_CLK_UNHALTED_CORE", "Unhalted core cycles (IAF)"},
+	{"CPU_CLK_UNHALTED_REF", "Unhalted reference cycles (IAF)"},
 	{ NULL, NULL } 
 };
 
@@ -334,8 +337,12 @@
 hwi_search_t i7Processor_map[] = {
 	{PAPI_BR_INS, {0, {PNE_I7_BR_INST_RETIRED_ALL_BRANCHES, PAPI_NULL}, {0,}}},
 	{PAPI_RES_STL, {0, {PNE_I7_RESOURCE_STALLS_ANY, PAPI_NULL}, {0,}}},
+/*
 	{PAPI_TOT_CYC, {0, {PNE_I7_CPU_CLK_UNHALTED_REF_P, PAPI_NULL}, {0,}}},
 	{PAPI_TOT_INS, {0, {PNE_I7_INST_RETIRED_ANY_P, PAPI_NULL}, {0,}}},
+*/
+	{PAPI_TOT_CYC, {0, {PNE_I7_CPU_CLK_UNHALTED_CORE, PAPI_NULL}, {0,}}},
+	{PAPI_TOT_INS, {0, {PNE_I7_INSTR_RETIRED_ANY, PAPI_NULL}, {0,}}},
 	{PAPI_HW_INT, {0, {PNE_I7_HW_INT_RCV, PAPI_NULL}, {0,}}},
 	{PAPI_BR_TKN, {0, {PNE_I7_BR_MISP_EXEC_TAKEN, PAPI_NULL}, {0,}}},
 	{PAPI_BR_MSP, {0, {PNE_I7_BR_MISP_EXEC_ANY, PAPI_NULL}, {0,}}},
