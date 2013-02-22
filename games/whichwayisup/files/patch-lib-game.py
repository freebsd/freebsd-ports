--- lib/game.py.orig	2012-10-21 13:48:24.000000000 +0200
+++ lib/game.py	2012-10-21 14:20:03.000000000 +0200
@@ -140,15 +140,15 @@
 
   if joystick != None:   # Parse joystick input
 
-    axis0 = joystick.get_axis(0)
+#    axis0 = joystick.get_axis(0)
 
-    if axis0 < -0.1:
-      inputs["LEFT"] = True
-      inputs["ANALOG"] = -axis0
-
-    if axis0 > 0.1:
-      inputs["RIGHT"] = True
-      inputs["ANALOG"] = axis0
+#    if axis0 < -0.1:
+#      inputs["LEFT"] = True
+#      inputs["ANALOG"] = -axis0
+
+#    if axis0 > 0.1:
+#      inputs["RIGHT"] = True
+#      inputs["ANALOG"] = axis0
 
     if joystick.get_numbuttons() > 1:
       if joystick.get_button(0):
@@ -165,16 +165,16 @@
         keys_released["J_B1"] = False
       else:
         keys_released["J_B1"] = True
-    else:
-      axis1 = joystick.get_axis(1)
+#    else:
+#      axis1 = joystick.get_axis(1)
 
-      if axis1 < -0.1:
-        inputs["UP"] = True
-        if keys_released["J_A1U"]:
-          inputs["JUMP"] = True
-        keys_released["J_A1U"] = False
-      else:
-        keys_released["J_A1U"] = True
+#      if axis1 < -0.1:
+#        inputs["UP"] = True
+#        if keys_released["J_A1U"]:
+#          inputs["JUMP"] = True
+#        keys_released["J_A1U"] = False
+#      else:
+#        keys_released["J_A1U"] = True
 
       if axis1 > 0.1:
         if keys_released["J_A1D"]:
