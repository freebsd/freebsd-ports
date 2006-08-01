--- data/py/configfile.py	Fri Jul 14 07:30:15 2006
+++ data/py/configfile.py	Tue Aug  1 00:01:53 2006
@@ -90,7 +90,7 @@
 			"68kclock":0,
 			"z80clock":0,
 			#Other thing section.
-			"libglpath":"/usr/lib/libGL.so",
+			"libglpath":"%%X11BASE%%/lib/libGL.so",
 			"sleepidle":"true",
 			"bench":"false",
 			},{ #XGngeo default.
