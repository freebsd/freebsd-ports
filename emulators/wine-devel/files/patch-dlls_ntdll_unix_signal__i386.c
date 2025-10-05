--- dlls/ntdll/unix/signal_i386.c.orig	2025-10-03 21:01:38 UTC
+++ dlls/ntdll/unix/signal_i386.c
@@ -827,7 +827,7 @@ static void fixup_frame_fpu_state( struct syscall_fram
     if (FPUX_sig(sigcontext))
     {
         if (user_shared_data->ProcessorFeatures[PF_XMMI_INSTRUCTIONS_AVAILABLE])
-            frame->u.xsave = *FPUX_sig(sigcontext);
+            frame->u.xsave = *((XSAVE_FORMAT *) FPUX_sig(sigcontext));
         else
             fpux_to_fpu( &frame->u.fsave, FPUX_sig(sigcontext) );
         frame->xstate.Mask = XSTATE_MASK_LEGACY;
