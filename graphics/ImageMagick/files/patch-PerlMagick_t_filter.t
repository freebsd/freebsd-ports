--- PerlMagick/t/filter.t.orig	2008-10-24 20:01:34.000000000 +0200
+++ PerlMagick/t/filter.t	2008-10-27 12:42:58.000000000 +0100
@@ -123,7 +123,7 @@
 testFilterCompare('input.miff',  q//, 'reference/filter/Modulate.miff', 'Modulate', q/brightness=>110,saturation=>110,hue=>110/, 0.005, 0.5);
 ++$test;
 
-testFilterCompare('input.miff',  q//, 'reference/filter/QuantizeMono.miff', 'Quantize', q/colorspace=>'gray',colors=>2,dither=>'false'/, 0.02, 1.02);
+testFilterCompare('input.miff',  q//, 'reference/filter/QuantizeMono.miff', 'Quantize', q/colorspace=>'gray',colors=>2,dither=>'false'/, 0.06, 1.02);
 ++$test;
 
 testFilterCompare('input.miff',  q//, 'reference/filter/MotionBlur.miff', 'MotionBlur', q/'0x13+10-10'/, 0.003, 0.03);
@@ -141,7 +141,7 @@
 testFilterCompare('input.miff', "fuzz=>$fuzz", 'reference/filter/Opaque.miff', 'Opaque', q/color=>"#e23834", fill=>"green"/, 0.03, 1.02);
 ++$test;
 
-testFilterCompare('input.miff',  q//, 'reference/filter/Quantize.miff', 'Quantize', q//, 0.003, 1.03);
+testFilterCompare('input.miff',  q//, 'reference/filter/Quantize.miff', 'Quantize', q//, 0.004, 1.03);
 ++$test;
 
 testFilterCompare('input.miff',  q//, 'reference/filter/RadialBlur.miff', 'RadialBlur', q/10/, 0.002, 0.02);
