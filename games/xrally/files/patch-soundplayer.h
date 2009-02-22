--- soundplayer.h.orig	2009-02-22 14:46:33.000000000 +1100
+++ soundplayer.h	2009-02-22 14:59:51.000000000 +1100
@@ -103,9 +103,9 @@
 #define vphase data[2]
 #define target data[0]
 
-#define fx_enable(x) do { x##.active = 1; } while (0)
-#define fx_disable(x) do { x##.active = 0; } while (0)
-#define fx_test(x) (x##.active != 0)
+#define fx_enable(x) do { x.active = 1; } while (0)
+#define fx_disable(x) do { x.active = 0; } while (0)
+#define fx_test(x) (x.active != 0)
 
 /* Sound driver stuff */
 
