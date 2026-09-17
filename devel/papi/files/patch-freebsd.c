--- freebsd.c.orig	2024-08-30 16:22:20.000000000 -0400
+++ freebsd.c	2025-02-03 19:23:59.366447000 -0500
@@ -21,7 +21,7 @@
 #include "freebsd.h"
 #include "papi_vector.h"
 
-#include "map.h"
+#include "freebsd/map.h"
 
 #include "freebsd-memory.h"
 #include "x86_cpuid_info.h"
@@ -358,7 +358,7 @@
 
 	for (i = 0; i < ctrl->n_counters; i++)
 	{
-		if ((ret = pmc_allocate (ctrl->counters[i], PMC_MODE_TC, 0, PMC_CPU_ANY, &(ctrl->pmcs[i]))) < 0)
+		if ((ret = pmc_allocate (ctrl->counters[i], PMC_MODE_TC, 0, PMC_CPU_ANY, &(ctrl->pmcs[i]), 0)) < 0)
 		{
 #if defined(DEBUG)
 			/* This shouldn't happen, it's tested previously on _papi_freebsd_allocate_registers */
@@ -824,7 +824,7 @@
 			ret = _papi_freebsd_ntv_code_to_name (ESI->NativeInfoArray[i].ni_event, name, sizeof(name));
 			if (ret != PAPI_OK)
 				return ret;
-			if ( (ret = pmc_allocate (name, PMC_MODE_TC, 0, PMC_CPU_ANY, &pmcs[i])) < 0)
+			if ( (ret = pmc_allocate (name, PMC_MODE_TC, 0, PMC_CPU_ANY, &pmcs[i], 0)) < 0)
 			{
 #if defined(DEBUG)
 				fprintf (stderr, "DEBUG: %s FAILED to allocate '%s' (%#08x) [%d of %d] ERROR = %d\n", FUNC, name, ESI->NativeInfoArray[i].ni_event, i+1, ESI->NativeCount, ret);
