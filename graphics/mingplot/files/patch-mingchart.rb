--- mingchart.rb.orig	Fri Aug 15 10:06:17 2003
+++ mingchart.rb	Fri Aug 15 10:06:20 2003
@@ -188,7 +188,7 @@
 
   def add_axises
     shape = SWFShape.new
-    shape.set_line(@axis_line_width, *@axis_line_color)
+    shape.set_line(@axis_line_width, *@axis_line_color.to_a)
     shape.move_pen(@canvas_x_margin, @canvas_y_margin)
     shape.draw_line(0, @y_length)
     shape.draw_line(@x_length, 0)
@@ -325,7 +325,7 @@
     item.move_to(xx + x_margin, yy + y_margin)
 
     line = SWFShape.new
-    line.set_line(@scale_line_width, *@scale_line_color)
+    line.set_line(@scale_line_width, *@scale_line_color.to_a)
     line.move_pen_to(xx, yy)
     if at == :bottom
       line.draw_line(0, -@s...)
@@ -354,7 +354,7 @@
       xx = convert_x(x)
       yy = @canvas_height - @canvas_y_margin
       line = SWFShape.new
-      line.set_line(@grid_line_width, *@grid_line_color)
+      line.set_line(@grid_line_width, *@grid_line_color.to_a)
       line.move_pen_to(xx, yy)
       line.draw_line(0, -@y...)
       @movie.add(line)
@@ -370,7 +370,7 @@
       xx = @canvas_x_margin
       yy = convert_y(y, side)
       line = SWFShape.new
-      line.set_line(@grid_line_width, *@grid_line_color)
+      line.set_line(@grid_line_width, *@grid_line_color.to_a)
       line.move_pen_to(xx, yy)
       line.draw_line(@x_length, 0)
       @movie.add(line)
@@ -424,7 +424,7 @@
 
   def draw_line (data, color, side, fill_p = false)
     line = SWFShape.new
-    line.set_line(@line_width, *color)
+    line.set_line(@line_width, *color.to_a)
     first_time = true
 
     if fill_p
@@ -549,8 +549,9 @@
       texts.push([text, width, height, lineno])
     }
 
-    total_height = texts.map {|x| x[2] }.inject(0) {|x, y| 
-      x + y *  @line_title_line_height_ratio 
+    total_height = 0
+    texts.map {|x| x[2] }.each {|v| 
+      total_height += v *  @line_title_line_height_ratio 
     }
     max_width = texts.map {|x| x[1] }.max
 
@@ -571,7 +572,7 @@
                    base_y + height + height * i * @line_title_line_height_ratio)
 
       line = SWFShape.new
-      line.set_line(@line_width, *@line_colors[lineno])
+      line.set_line(@line_width, *@line_colors[lineno].to_a)
       line.draw_line(@line_title_line_length, 0)
       item = @movie.add(line)
       item.move_to(base_x + @line_title_line_margin,

