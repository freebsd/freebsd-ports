GCC generates instructions that require variables to be aligned in memory on
certain CPUs. Our libthr does not have the required alignment so these CPUs fail
to execute these instructions. The instructions generation is driven by CPUTYPE.
Some CPUs are fine to execute these instructions on unaligned data.

This patch explicitly forbids GCC to generate instructions that require
alignment of the data.

If the entire program is compiled by LLVM or GCC, there is no problem (with GCC
everything is aligned, with LLVM vmovdqa is not used to assign both variables
at once).

Linux does not have libthr, so Linux is not affected. Moreover Linux is likely
to build everything with GCC.

This patch will become obsolete once all supported FreeBSD releases
include commit 22e564c74eb20e14bd93fd9fdde20e38a29cfcf1.

--- libgcc/unwind.inc.orig	2025-04-12 08:18:17 UTC
+++ libgcc/unwind.inc
@@ -212,8 +212,8 @@ _Unwind_ForcedUnwind (struct _Unwind_Exception *exc,
   uw_init_context (&this_context);
   cur_context = this_context;
 
-  exc->private_1 = (_Unwind_Ptr) stop;
-  exc->private_2 = (_Unwind_Ptr) stop_argument;
+  __builtin_memcpy(&exc->private_1, &stop, sizeof(_Unwind_Ptr));
+  __builtin_memcpy(&exc->private_2, &stop_argument, sizeof(_Unwind_Ptr));
 
   code = _Unwind_ForcedUnwind_Phase2 (exc, &cur_context, &frames);
   if (code != _URC_INSTALL_CONTEXT)
