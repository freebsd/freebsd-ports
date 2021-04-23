--- mecrisp-stellaris-source/freebsd-ra/terminal.s.orig	2021-04-10 12:49:15 UTC
+++ mecrisp-stellaris-source/freebsd-ra/terminal.s
@@ -167,7 +167,6 @@ serial_key: @ ( -- c ) Receive one character
 cacheflush:
 @ -----------------------------------------------------------------------------
 
-.ifdef m0core
   @ ARMv6 hat keine Speicherbarrieren.  Das muss über einen syscall realisiert werden
   push {r4-r7, lr}
   movs r0, #0      @ ARM_SYNC_ICACHE
@@ -180,14 +179,6 @@ cacheflush:
   @ Datenstruktur arm_sync_icache_args für den sysarch-Aufruf
 0:.word incipit
   .word totalsize
-
-.else
-  @ auf ARMv7 und später nehmen wir einfach die Barrien-Befehle
-  dmb
-  dsb
-  isb  
-  bx lr
-.endif
 
 @ -----------------------------------------------------------------------------
   Wortbirne Flag_foldable_0, "arguments" @ ( -- a-addr )
