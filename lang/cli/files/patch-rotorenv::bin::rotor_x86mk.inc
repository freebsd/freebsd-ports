
$FreeBSD$

--- rotorenv/bin/rotor_x86mk.inc.orig	Sat Nov  2 04:22:40 2002
+++ rotorenv/bin/rotor_x86mk.inc	Fri Apr 25 11:06:16 2003
@@ -329,7 +329,7 @@
 CC_LIB              =$(GCC_LIB_DIR)/libgcc.a $(GCC_EH_LIB) \
                      /usr/local/lib/libstdc++.a
 !else
-CC_LIB              =/usr/lib/libgcc.a
+CC_LIB              =%%GCC_LIB%%
 !endif
 !else
 ASM_SUFFIX          =asm
@@ -362,7 +362,7 @@
 
 !IFNDEF COMPILER_WARNINGS
 !IFDEF PLATFORM_UNIX
-COMPILER_WARNINGS=-Wall -Wno-non-virtual-dtor -Wno-non-template-friend
+COMPILER_WARNINGS=-Wno-non-virtual-dtor -Wno-non-template-friend -w
 !ENDIF
 !ENDIF
 
