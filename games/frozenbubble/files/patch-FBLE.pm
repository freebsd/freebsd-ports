--- lib/FBLE.pm.orig	Sun Nov  7 00:25:46 2004
+++ lib/FBLE.pm	Sun Nov  7 00:26:25 2004
@@ -1094,11 +1094,19 @@
     $rect{screenshot} = SDL::Rect->new(-x => $POS_1P{p1}{left_limit} - 40, '-y' => 0, 
 				       -width => $POS_1P{p1}{right_limit} - $POS_1P{p1}{left_limit} + 80,
 				       -height => $POS_1P{bottom_limit} - $POS_1P{init_top_limit} + 190);
-    fb_c_stuff::shrink($app->{-surface},
-		       $file_browser_screenshots[$list_browser_highlight_offset]->display_format()->{-surface},
-		       $rect{middle}->x + $rect{middle}->width - $rect{screenshot}->width/4 - 12,
-		       $rect{middle}->y + $rect{middle}->height/2 - $rect{screenshot}->height/8 - 3,
-		       $rect{screenshot}{-rect}, 4);
+    if (UNIVERSAL::isa($app, "HASH")) {
+        fb_c_stuff::shrink($app->{-surface},
+			   $file_browser_screenshots[$list_browser_highlight_offset]->display_format()->{-surface},
+			   $rect{middle}->x + $rect{middle}->width - $rect{screenshot}->width/4 - 12,
+			   $rect{middle}->y + $rect{middle}->height/2 - $rect{screenshot}->height/8 - 3,
+			   $rect{screenshot}{-rect}, 4);
+    } else {
+        fb_c_stuff::shrink($$app,
+			   ${$file_browser_screenshots[$list_browser_highlight_offset]->display_format()},
+			   $rect{middle}->x + $rect{middle}->width - $rect{screenshot}->width/4 - 12,
+			   $rect{middle}->y + $rect{middle}->height/2 - $rect{screenshot}->height/8 - 3,
+			   ${$rect{screenshot}}, 4);
+    }
 }
 
 
