--- server/plugins/gdasflange.c.orig	Sat Feb 23 01:17:35 2002
+++ server/plugins/gdasflange.c	Thu Nov  6 18:01:13 2003
@@ -92,10 +92,12 @@
 	      int delay;
 	      int value;
 	      int volume;
+	      GdamSample sample;
 	      delay = flange->echoes[echo].delay;
 	      delay = (gint64) factor *delay / GdamFixed_ONE;
-	      value = gdas_buffering_filter_sample_at
-		(buffering_filter, delay).s[channel];
+	      sample = gdas_buffering_filter_sample_at
+		(buffering_filter, delay);
+	      value = sample.s[channel];
 	      volume = flange->echoes[echo].volume;
 	      sum += GDAM_FIXED_MUL (volume, value);
 	    }
