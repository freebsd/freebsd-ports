--- lib/interp/extern_call.nim.orig	2026-10-29 10:03:59 UTC
+++ lib/interp/extern_call.nim
@@ -35,8 +35,9 @@ import ../runtime/coupler_client
 import ../runtime/libmgr
 import ../runtime/coupler_client
 
-when not (defined(amd64) or defined(arm64)):
-  {.error: "interpreter extern FFI needs the x86-64 SysV or AAPCS64 calling convention".}
+when not (defined(amd64) or defined(arm64) or defined(powerpc64) or
+    defined(powerpc64el)):
+  {.error: "interpreter extern FFI needs the x86-64 SysV, AAPCS64 or 64-bit PowerPC ELF calling convention".}
 
 type
   ExternError* = object of CatchableError
@@ -156,6 +157,14 @@ proc callExtern*(def: Node, args: seq[AwkValue], outs:
       var a = args[i]
       da[nd] = toNum(a); inc nd
     else:
+      when defined(powerpc64) or defined(powerpc64el):
+        # 64-bit PowerPC ELF: parameter i owns doubleword i of the parameter
+        # area, so an integer-class one is passed in r3+i even after cdoubles
+        # (those go to the next FPR but still use up their GPR).
+        if i >= ia.len:
+          raise newException(ExternError, "extern '" & def.extAwkName &
+            "': integer-class parameters past the 6th are not supported by --interp")
+        ni = i
       if ni >= ia.len:
         raise newException(ExternError, "extern '" & def.extAwkName &
           "': more than 6 integer-class parameters are not supported by --interp")
