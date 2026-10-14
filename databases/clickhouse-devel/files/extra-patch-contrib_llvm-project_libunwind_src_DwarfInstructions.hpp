--- contrib/llvm-project/libunwind/src/DwarfInstructions.hpp.orig	2026-06-10 14:59:56 UTC
+++ contrib/llvm-project/libunwind/src/DwarfInstructions.hpp
@@ -292,10 +292,6 @@ int DwarfInstructions<A, R>::stepWithDwarf(
                                     prolog.savedRegisters[i]));
           else
             return UNW_EBADREG;
-        } else if (i == (int)cieInfo.returnAddressRegister) {
-            // Leaf function keeps the return address in register and there is no
-            // explicit instructions how to restore it.
-            returnAddress = registers.getRegister(cieInfo.returnAddressRegister);
         }
       }
 
