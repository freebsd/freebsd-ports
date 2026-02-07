    [clang] Declare core_func_retval()
    
    This fixes the clang build failure
    
      ./vaults.des: line 110, pos 9 : Core function 'level.depth' has
        unknown return type 'i'.
      ./vaults.des: line 110, pos 9 : syntax error at level.depth
    
    Because core_func_retval() wasn't declared, it was defaulting to
    return type **int**. So you could get, for instance, return
    value 361 (which is 'i' + 256 .. high bits of the return value
    were being kept, instead of discarded as they might for a narrower type).

--- util/lev_comp.l.orig	2017-12-20 08:11:18 UTC
+++ util/lev_comp.l
@@ -80,6 +80,8 @@ void FDECL(savetoken, (char *));
 void NDECL(newline);
 void FDECL(advancepos, (char *));
 
+extern char FDECL(core_func_retval, (int idx));
+
 /*
  * This doesn't always get put in lev_comp.h
  * (esp. when using older versions of bison).
