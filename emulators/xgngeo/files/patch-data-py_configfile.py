--- data/py/configfile.py	Sun Oct  1 20:52:46 2006
+++ data/py/configfile.py	Sun Oct  1 20:53:13 2006
@@ -107,7 +107,7 @@
 			"68kclock": 0,
 			"z80clock": 0,
 			#Other thing section.
-			"libglpath": "/usr/lib/libGL.so",
+			"libglpath": "%%LOCALBASE%%/lib/libGL.so",
 			"sleepidle": "true",
 			"bench": "false",
 			},{ #XGngeo's default.
