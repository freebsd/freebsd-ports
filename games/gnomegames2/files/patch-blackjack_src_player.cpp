--- blackjack/src/player.cpp.orig	Tue Jul  6 12:56:50 2004
+++ blackjack/src/player.cpp	Tue Jul  6 12:59:29 2004
@@ -262,8 +262,8 @@
         // Player can always stand.
 
         bestValue = value = getValueStand (*lplayer, upCard);
-        mark_list[num_options++] = g_strdup_printf ("  %s     %8.2lf%%\n", 
-                                                    _("Stand"), value * 100);
+        mark_list[num_options++] = g_strdup_printf ("  %s     %8.2Lf%%\n", 
+                                                    _("Stand"), (long double)(value * 100));
         bestOption = KEY_S;
         bestOptionNumber = num_options;
 
@@ -271,8 +271,8 @@
         if (bj_hand_can_be_hit ()) {
                 value = getValueHit (*lplayer, upCard);
                 
-                mark_list[num_options++] = g_strdup_printf ("  %s       %8.2lf%%\n", 
-                                                            _("Hit"), value * 100);
+                mark_list[num_options++] = g_strdup_printf ("  %s       %8.2Lf%%\n", 
+                                                            _("Hit"), (long double)(value * 100));
                 if (value > bestValue) {
                         bestValue = value;
                         bestOption = KEY_H;
@@ -282,8 +282,8 @@
                 // Check if player can double down.
                 if (bj_hand_can_be_doubled ()) {
                         value = getValueDoubleDown (*lplayer, upCard);
-                        mark_list[num_options++] = g_strdup_printf ("  %s    %8.2lf%%\n", 
-                                                                    _("Double"), value * 100);
+                        mark_list[num_options++] = g_strdup_printf ("  %s    %8.2Lf%%\n", 
+                                                                    _("Double"), (long double)(value * 100));
                         if (value > bestValue) {
                                 bestValue = value;
                                 bestOption = KEY_D;
@@ -296,8 +296,8 @@
 
         if (bj_hand_can_be_split ()) {
                 value = getValueSplit(lplayer->cards[0].value (), upCard);
-                mark_list[num_options++] = g_strdup_printf ("  %s     %8.2lf%%\n", 
-                                                            _("Split"), value * 100);
+                mark_list[num_options++] = g_strdup_printf ("  %s     %8.2Lf%%\n", 
+                                                            _("Split"), (long double)(value * 100));
                 if (value > bestValue) {
                         bestValue = value;
                         bestOption = KEY_P;
@@ -308,8 +308,8 @@
         // Check if player can surrender.
         if (bj_hand_can_be_surrendered ()) {
                 value = -0.5;
-                mark_list[num_options++] = g_strdup_printf ("  %s %8.2lf%%\n", 
-                                                            _("Surrender"), value * 100);
+                mark_list[num_options++] = g_strdup_printf ("  %s %8.2Lf%%\n", 
+                                                            _("Surrender"), (long double)(value * 100));
                 if (value > bestValue) {
                         bestValue = value;
                         bestOption = KEY_R;
@@ -439,12 +439,12 @@
         reset ();
 
         mark_list[0] = g_strdup_printf ("<b>%s</b>\n", _("Dealer hand probabilities"));
-        mark_list[1] = g_strdup_printf ("  %s         %5.2lf%%\n", _("Bust"),
-                                        getProbabilityBust (lupCard) * 100.0 / notBlackjack);
+        mark_list[1] = g_strdup_printf ("  %s         %5.2Lf%%\n", _("Bust"),
+                                        (long double)(getProbabilityBust (lupCard) * 100.0 / notBlackjack));
         for (int count = 17; count <= 21; count++) {
-                mark_list[count-15] = g_strdup_printf ("  %2d           %5.2lf%%\n", count,
-                                                       getProbabilityCount (count, lupCard)
-                                                       * 100.0 / notBlackjack);
+                mark_list[count-15] = g_strdup_printf ("  %2d           %5.2Lf%%\n", count,
+                                                       (long double)(getProbabilityCount (count, lupCard)
+                                                       * 100.0 / notBlackjack));
         }
 
         markup = g_strconcat ("<span size=\"small\" font_family=\"monospace\" foreground=\"#eaeac1\">", 
