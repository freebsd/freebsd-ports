--- ./freebsd/map-core.c.orig	2009-07-15 12:05:10.649730000 -0400
+++ ./freebsd/map-core.c	2009-07-15 12:05:10.652723000 -0400
@@ -0,0 +1,168 @@
+/****************************/
+/* THIS IS OPEN SOURCE CODE */
+/****************************/
+
+/* 
+* File:    map-core.c
+* CVS:     $Id: map-core.c,v 1.2 2009/07/09 13:02:26 servat Exp $
+* Author:  Harald Servat
+*          redcrash@gmail.com
+*/
+
+#include SUBSTRATE
+#include "papiStdEventDefs.h"
+#include "map.h"
+
+/****************************************************************************
+ CORE SUBSTRATE 
+ CORE SUBSTRATE 
+ CORE SUBSTRATE
+ CORE SUBSTRATE
+ CORE SUBSTRATE
+****************************************************************************/
+
+/*
+        NativeEvent_Value_CoreProcessor must match CoreProcessor_info 
+*/
+
+Native_Event_LabelDescription_t CoreProcessor_info[] =
+{
+	{"BAClears", "The number of BAClear conditions asserted."},
+	{"BTB_Misses", "The number of branches for which the branch table buffer did not produce a prediction."},
+	{"Br_BAC_Missp_Exec", "The number of branch instructions executed that were mispredicted at the front end."},
+	{"Br_Bogus", "The number of bogus branches."},
+	{"Br_Call_Exec", "The number of CALL instructions executed."},
+	{"Br_Call_Missp_Exec", "The number of CALL instructions executed that were mispredicted."},
+	{"Br_Cnd_Exec", "The number of conditional branch instructions executed."},
+	{"Br_Cnd_Missp_Exec", "The number of conditional branch instructions executed that were mispredicted."},
+	{"Br_Ind_Call_Exec", "The number of indirect CALL instructions executed."},
+	{"Br_Ind_Exec", "The number of indirect branches executed."},
+	{"Br_Ind_Missp_Exec", "The number of indirect branch instructions executed that were mispredicted."},
+	{"Br_Inst_Exec", "The number of branch instructions executed including speculative branches."},
+	{"Br_Instr_Decoded", "The number of branch instructions decoded."},
+	{"Br_Instr_Ret", "The number of branch instructions retired. This is an architectural performance event."},
+	{"Br_MisPred_Ret", "The number of mispredicted branch instructions retired. This is an architectural performance event."},
+	{"Br_MisPred_Taken_Ret", "The number of taken and mispredicted branches retired."},
+	{"Br_Missp_Exec", "The number of branch instructions executed and mispredicted at execution including branches that were not predicted."},
+	{"Br_Ret_BAC_Missp_Exec", "The number of return branch instructions that were mispredicted at the front end."},
+	{"Br_Ret_Exec", "The number of return branch instructions executed."},
+	{"Br_Ret_Missp_Exec", "The number of return branch instructions executed that were mispredicted."},
+	{"Br_Taken_Ret", "The number of taken branches retired."},
+	{"Bus_BNR_Clocks", "was asserted."},
+	{"Bus_DRDY_Clocks", "The number of external bus cycles while DRDY was asserted."},
+	{"Bus_Data_Rcv", "The number of cycles during which the processor is busy receiving data."},
+	{"Bus_Locks_Clocks", "The number of external bus cycles while the bus lock signal was asserted."},
+	{"Bus_Not_In_Use", "The number of cycles when there is no transaction from the core."},
+	{"Bus_Req_Outstanding", "The weighted cycles of cacheable bus data read requests from the data cache unit or hardware prefetcher."},
+	{"Bus_Snoop_Stall", "The number bus cycles while a bus snoop is stalled."},
+	{"Bus_Snoops", "The number of snoop responses to bus transactions."},
+	{"Bus_Trans_Any", "The number of completed bus transactions."},
+	{"Bus_Trans_Brd", "The number of read bus transactions."},
+	{"Bus_Trans_Burst", "The number of completed burst transactions.  Retried transactions may be counted more than once."},
+	{"Bus_Trans_Def", "The number of completed deferred transactions."},
+	{"Bus_Trans_IO", "The number of completed I/O transactions counting both reads and writes."},
+	{"Bus_Trans_Ifetch", "Completed instruction fetch transactions."},
+	{"Bus_Trans_Inval", "The number completed invalidate transactions."},
+	{"Bus_Trans_Mem", "The number of completed memory transactions."},
+	{"Bus_Trans_P", "The number of completed partial transactions."},
+	{"Bus_Trans_Pwr", "The number of completed partial write transactions."},
+	{"Bus_Trans_RFO", "The number of completed read-for-ownership transactions."},
+	{"Bus_Trans_WB", "The number of completed writeback transactions from the data cache unit, excluding L2 writebacks."},
+	{"Cycles_Div_Busy", "The number of cycles the divider is busy.  The event is only available on PMC0."},
+	{"Cycles_Int_Masked", "The number of cycles while interrupts were disabled."},
+	{"Cycles_Int_Pending_Masked", "The number of cycles while interrupts were disabled and interrupts were pending."},
+	{"DCU_Snoop_To_Share", "The number of data cache unit snoops to L1 cache lines in the shared state."},
+	{"DCache_Cache_Lock", "The number of cacheable locked read operations to invalid state."},
+	{"DCache_Cache_LD", "The number of cacheable L1 data read operations."},
+	{"DCache_Cache_ST", "The number cacheable L1 data write operations."},
+	{"DCache_M_Evict", "The number of M state data cache lines that were evicted."},
+	{"DCache_M_Repl", "The number of M state data cache lines that were allocated."},
+	{"DCache_Pend_Miss", "The weighted cycles an L1 miss was outstanding."},
+	{"DCache_Repl", "The number of data cache line replacements."},
+	{"Data_Mem_Cache_Ref", "The number of cacheable read and write operations to L1 data cache."},
+	{"Data_Mem_Ref", "The number of L1 data reads and writes, both cacheable and uncacheable."},
+	{"Dbus_Busy", "The number of core cycles during which the data bus was busy."},
+	{"Dbus_Busy_Rd", "The nunber of cycles during which the data bus was busy transferring data to a core."},
+	{"Div", "The number of divide operations including speculative operations for integer and floating point divides. This event can only be counted on PMC1."},
+	{"Dtlb_Miss", "The number of data references that missed the TLB."},
+	{"ESP_Uops", "The number of ESP folding instructions decoded."},
+	{"EST_Trans", "Count the number of Intel Enhanced SpeedStep transitions."},
+	{"FP_Assist", "The number of floating point operations that required microcode assists.  The event is only available on PMC1."},
+	{"FP_Comp_Instr_Ret", "The number of X87 floating point compute instructions retired.  The event is only available on PMC0."},
+	{"FP_Comps_Op_Exe", "The number of floating point computational instructions executed."},
+	{"FP_MMX_Trans", "The number of transitions from X87 to MMX."},
+	{"Fused_Ld_Uops_Ret", "The number of fused load uops retired."},
+	{"Fused_St_Uops_Ret", "The number of fused store uops retired."},
+	{"Fused_Uops_Ret", "The number of fused uops retired."},
+	{"HW_Int_Rx", "The number of hardware interrupts received."},
+	{"ICache_Misses", "The number of instruction fetch misses in the instruction cache and streaming buffers."},
+	{"ICache_Reads", "The number of instruction fetches from the the instruction cache and streaming buffers counting both cacheable and uncacheable fetches."},
+	{"IFU_Mem_Stall", "The number of cycles the instruction fetch unit was stalled while waiting for data from memory."},
+	{"ILD_Stall", "The number of instruction length decoder stalls."},
+	{"ITLB_Misses", "The number of instruction TLB misses."},
+	{"Instr_Decoded", "The number of instructions decoded."},
+	{"Instr_Ret", "The number of instructions retired. This is an architectural performance event."},
+	{"L1_Pref_Req", "The number of L1 prefetch request due to data cache misses."},
+	{"L2_ADS", "The number of L2 address strobes."},
+	{"L2_IFetch", "The number of instruction fetches by the instruction fetch unit from L2 cache including speculative fetches."},
+	{"L2_LD", "The number of L2 cache reads."},
+	{"L2_Lines_In", "The number of L2 cache lines allocated."},
+	{"L2_Lines_Out", "The number of L2 cache lines evicted."},
+	{"L2_M_Lines_In", "The number of L2 M state cache lines allocated."},
+	{"L2_M_Lines_Out", "The number of L2 M state cache lines evicted."},
+	{"L2_No_Request_Cycles", "The number of cycles there was no request to access L2 cache."},
+	{"L2_Reject_Cycles", "The number of cycles the L2 cache was busy and rejecting new requests."},
+	{"L2_Rqsts", "The number of L2 cache requests."},
+	{"L2_ST", "The number of L2 cache writes including speculative writes."},
+	{"LD_Blocks", "The number of load operations delayed due to store buffer blocks."},
+	{"LLC_Misses", "The number of cache misses for references to the last level cache, excluding misses due to hardware prefetches. This is an architectural performance event."},
+	{"LLC_Reference", "The number of references to the last level cache, excluding those due to hardware prefetches. This is an architectural performance event."},
+	{"MMX_Assist", "The number of EMMX instructions executed."},
+	{"MMX_FP_Trans", "The number of transitions from MMX to X87."},
+	{"MMX_Instr_Exec", "The number of MMX instructions executed excluding MOVQ and MOVD stores."},
+	{"MMX_Instr_Ret", "The number of MMX instructions retired."},
+	{"Misalign_Mem_Ref", "The number of misaligned data memory references, counting loads and stores."},
+	{"Mul", "The number of multiply operations include speculative floating point and integer multiplies. This event is available on PMC1 only."},
+	{"NonHlt_Ref_Cycles", "The number of non-halted bus cycles. This is an architectural performance event."},
+	{"Pref_Rqsts_Dn", "The number of hardware prefetch requests issued in backward streams."},
+	{"Pref_Rqsts_Up", "The number of hardware prefetch requests issued in forward streams."},
+	{"Resource_Stall", "The number of cycles where there is a resource related stall."},
+	{"SD_Drains", "The number of cycles while draining store buffers."},
+	{"SIMD_FP_DP_P_Ret", "The number of SSE/SSE2 packed double precision instructions retired."},
+	{"SIMD_FP_DP_P_Comp_Ret", "The number of SSE/SSE2 packed double precision compute instructions retired."},
+	{"SIMD_FP_DP_S_Ret", "The number of SSE/SSE2 scalar double precision instructions retired."},
+	{"SIMD_FP_DP_S_Comp_Ret", "The number of SSE/SSE2 scalar double precision compute instructions retired."},
+	{"SIMD_FP_SP_P_Comp_Ret", "The number of SSE/SSE2 packed single precision compute instructions retired."},
+	{"SIMD_FP_SP_Ret", "The number of SSE/SSE2 scalar single precision instructions retired, both packed and scalar."},
+	{"SIMD_FP_SP_S_Ret", "The number of SSE/SSE2 scalar single precision instructions retired."},
+	{"SIMD_FP_SP_S_Comp_Ret", "The number of SSE/SSE2 single precision compute instructions retired."},
+	{"SIMD_Int_128_Ret", "The number of SSE2 128-bit integer instructions retired."},
+	{"SIMD_Int_Pari_Exec", "The number of SIMD integer packed arithmetic instructions executed."},
+	{"SIMD_Int_Pck_Exec", "The number of SIMD integer pack operations instructions executed."},
+	{"SIMD_Int_Plog_Exec", "The number of SIMD integer packed logical instructions executed."},
+	{"SIMD_Int_Pmul_Exec", "The number of SIMD integer packed multiply instructions executed."},
+	{"SIMD_Int_Psft_Exec", "The number of SIMD integer packed shift instructions executed."},
+	{"SIMD_Int_Sat_Exec", "The number of SIMD integer saturating instructions executed."},
+	{"SIMD_Int_Upck_Exec", "The number of SIMD integer unpack instructions executed."},
+	{"SMC_Detected", "The number of times self-modifying code was detected."},
+	{"SSE_NTStores_Miss", "The number of times an SSE streaming store instruction missed all caches."},
+	{"SSE_NTStores_Ret", "The number of SSE streaming store instructions executed."},
+	{"SSE_PrefNta_Miss", "The number of times PREFETCHNTA missed all caches."},
+	{"SSE_PrefNta_Ret", "The number of PREFETCHNTA instructions retired."},
+	{"SSE_PrefT1_Miss", "The number of times PREFETCHT1 missed all caches."},
+	{"SSE_PrefT1_Ret", "The number of PREFETCHT1 instructions retired."},
+	{"SSE_PrefT2_Miss", "The number of times PREFETCHNT2 missed all caches."},
+	{"SSE_PrefT2_Ret", "The number of PREFETCHT2 instructions retired."},
+	{"Seg_Reg_Loads", "The number of segment register loads."},
+	{"Serial_Execution_Cycles", "The number of non-halted bus cycles of this code while the other core was halted."},
+	{"Thermal_Trip", "The duration in a thermal trip based on the current core clock."},
+	{"Unfusion", "The number of unfusion events."},
+	{"Unhalted_Core_Cycles", "The number of core clock cycles when the clock signal on a specific core is not halted. This is an architectural performance event."},
+	{"Uops_Ret", "The number of micro-ops retired."},
+	{ NULL, NULL }
+};
+
+/* PAPI PRESETS */
+hwi_search_t CoreProcessor_map[] = {
+	{0, {0, {PAPI_NULL}, {0,}}}
+};
