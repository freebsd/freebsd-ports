amd: Make vgpr-spilling depend on llvm version 

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230789#c14
diff --git a/src/amd/common/ac_llvm_util.c b/src/amd/common/ac_llvm_util.c
index 69d9f7b9f3fe9e5feb07b32c35cbcf1206a14ca8..dc9b684e9dd287d5bb558d9ad3868a9d0975228d 100644
--- src/amd/common/ac_llvm_util.c
+++ src/amd/common/ac_llvm_util.c
@@ -153,7 +153,8 @@ static LLVMTargetMachineRef ac_create_target_machine(enum radeon_family family,
 	LLVMTargetRef target = ac_get_llvm_target(triple);
 
 	snprintf(features, sizeof(features),
-		 "+DumpCode,+vgpr-spilling,-fp32-denormals,+fp64-denormals%s%s%s%s",
+		 "+DumpCode,-fp32-denormals,+fp64-denormals%s%s%s%s%s",
+		 HAVE_LLVM >= 0x0800 ? "" : ",+vgpr-spilling",
 		 tm_options & AC_TM_SISCHED ? ",+si-scheduler" : "",
 		 tm_options & AC_TM_FORCE_ENABLE_XNACK ? ",+xnack" : "",
 		 tm_options & AC_TM_FORCE_DISABLE_XNACK ? ",-xnack" : "",
