commit eda36feb2b7eef8347f579c3c8590a8f09017cf0
Author: Mark Janes <mark.a.janes@intel.com>
Date:   Fri Apr 5 11:39:18 2019 -0700

    intel/tools: Remove redundant definitions of INTEL_DEBUG
    
    INTEL_DEBUG is declared extern and defined in gen_debug.c
    
    Reviewed-by: Kenneth Graunke <kenneth@whitecape.org>

diff --git src/intel/common/gen_disasm.c src/intel/common/gen_disasm.c
index 4f835c19883..656613cd931 100644
--- src/intel/common/gen_disasm.c
+++ src/intel/common/gen_disasm.c
@@ -28,8 +28,6 @@
 
 #include "gen_disasm.h"
 
-uint64_t INTEL_DEBUG;
-
 struct gen_disasm {
     struct gen_device_info devinfo;
 };
diff --git src/intel/tools/i965_disasm.c src/intel/tools/i965_disasm.c
index 79434e6462a..5fe4afa35ff 100644
--- src/intel/tools/i965_disasm.c
+++ src/intel/tools/i965_disasm.c
@@ -29,8 +29,6 @@
 #include "compiler/brw_eu.h"
 #include "dev/gen_device_info.h"
 
-uint64_t INTEL_DEBUG;
-
 /* Return size of file in bytes pointed by fp */
 static size_t
 i965_disasm_get_file_size(FILE *fp)
