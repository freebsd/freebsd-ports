--- game.c	Thu Jul 31 10:06:51 2003
+++ game.c	Mon Nov 17 09:50:58 2003
@@ -363,7 +363,7 @@
 	try_load_sample (boom, "sfx/boom.wav");
 	try_load_sample (crash, "sfx/crash.wav");
 	try_load_sample (gold, "sfx/gold.wav");
-	try_load_sample (pit, "sfx/pit.wav");
+	try_load_sample (pit, "sfx/crash.wav");  /* pit.wav is corrupt? */
 	try_load_sample (spell, "sfx/spell.wav");
 	try_load_sample (step, "sfx/step.wav");
 	try_load_sample (attack, "sfx/attack.wav");
