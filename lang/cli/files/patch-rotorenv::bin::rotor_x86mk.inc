
$FreeBSD$

--- rotorenv/bin/rotor_x86mk.inc.orig	Thu Jun 20 02:44:05 2002
+++ rotorenv/bin/rotor_x86mk.inc	Tue Jul 30 15:45:22 2002
@@ -336,7 +336,7 @@
 
 !IFNDEF COMPILER_WARNINGS
 !IFDEF PLATFORM_UNIX
-COMPILER_WARNINGS=-Wall -Wno-non-virtual-dtor -Wno-non-template-friend
+COMPILER_WARNINGS=-Wno-non-virtual-dtor -Wno-non-template-friend -w
 !ENDIF
 !ENDIF
 
