
$FreeBSD$

--- ../../collects/plot/scribblings/ticks.scrbl.orig
+++ ../../collects/plot/scribblings/ticks.scrbl
@@ -182,22 +182,6 @@
 @doc-apply[plot-y-far-ticks]
 @doc-apply[plot-z-ticks]
 @doc-apply[plot-z-far-ticks]{
-@examples[#:eval plot-eval
-                 (parameterize ([plot-x-label      "Near x axis"]
-                                [plot-y-label      "Near y axis"]
-                                [plot-z-label      "Near z axis"]
-                                [plot-x-ticks      (date-ticks)]
-                                [plot-y-ticks      (time-ticks)]
-                                [plot-z-ticks      (fraction-ticks)]
-                                [plot-x-far-label  "Far x axis"]
-                                [plot-y-far-label  "Far y axis"]
-                                [plot-z-far-label  "Far z axis"]
-                                [plot-x-far-ticks  (linear-ticks)]
-                                [plot-y-far-ticks  (currency-ticks)]
-                                [plot-z-far-ticks  (log-ticks #:base 2)])
-                   (plot3d (lines3d '(#(1 1 1) #(40000000 4 4)) #:style 'transparent)
-                           #:angle 45 #:altitude 50
-                           #:title "Axis Names and Tick Locations"))]
 At any @racket[#:angle], the far @italic{x} and @italic{y} ticks are behind the plot, and the far @italic{z} ticks are on the right.
 Far ticks are drawn, but not labeled, if they are identical to their corresponding near ticks.
 They are always identical by default.
