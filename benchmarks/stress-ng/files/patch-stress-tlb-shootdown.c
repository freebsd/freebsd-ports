--- stress-tlb-shootdown.c.orig	2021-12-28 15:45:13 UTC
+++ stress-tlb-shootdown.c
@@ -64,7 +64,7 @@ static int stress_tlb_shootdown(const stress_args_t *a
 		const int32_t max_cpus = stress_get_processors_configured();
 
 		CPU_ZERO(&proc_mask);
-		CPU_OR(&proc_mask, &proc_mask_initial, &proc_mask);
+		CPU_OR(&proc_mask, &proc_mask_initial);
 
 		tlb_procs = max_cpus;
 		if (tlb_procs > MAX_TLB_PROCS)
