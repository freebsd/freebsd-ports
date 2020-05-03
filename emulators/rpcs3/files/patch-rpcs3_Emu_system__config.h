https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=240495

--- rpcs3/Emu/system_config.h.orig	2020-05-02 11:57:38 UTC
+++ rpcs3/Emu/system_config.h
@@ -28,7 +28,11 @@ struct cfg_root : cfg::node
 		cfg::_int<0, INT32_MAX> llvm_threads{ this, "Max LLVM Compile Threads", 0 };
 		cfg::_bool thread_scheduler_enabled{ this, "Enable thread scheduler", thread_scheduler_enabled_def };
 		cfg::_bool set_daz_and_ftz{ this, "Set DAZ and FTZ", false };
+#if defined(__FreeBSD__) && __FreeBSD__ < 12
+		cfg::_enum<spu_decoder_type> spu_decoder{ this, "SPU Decoder", spu_decoder_type::asmjit };
+#else
 		cfg::_enum<spu_decoder_type> spu_decoder{ this, "SPU Decoder", spu_decoder_type::llvm };
+#endif
 		cfg::_bool lower_spu_priority{ this, "Lower SPU thread priority" };
 		cfg::_bool spu_debug{ this, "SPU Debug" };
 		cfg::_int<0, 6> preferred_spu_threads{ this, "Preferred SPU Threads", 0, true }; // Number of hardware threads dedicated to heavy simultaneous spu tasks
