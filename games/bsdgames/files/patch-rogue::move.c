$FreeBSD$

--- rogue/move.c	30 Nov 1999 03:49:24 -0000	1.7
+++ rogue/move.c	21 Aug 2003 20:02:38 -0000
@@ -64,7 +64,6 @@
 extern short cur_level, max_level;
 extern short bear_trap, haste_self, confused;
 extern short e_rings, regeneration, auto_search;
-extern char hunger_str[];
 extern boolean being_held, interrupted, r_teleport, passgo;
 
 one_move_rogue(dirch, pickup)
