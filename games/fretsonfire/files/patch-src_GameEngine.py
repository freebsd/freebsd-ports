--- src/GameEngine.py	Tue Oct  3 09:25:05 2006
+++ src/GameEngine.py	Tue Oct  3 09:25:33 2006
@@ -46,7 +46,7 @@
 Config.define("engine", "tickrate",     float, 1.0)
 Config.define("game",   "uploadscores", bool,  False, text = "Upload Highscores",    options = {False: "No", True: "Yes"})
 Config.define("game",   "uploadurl",    str,   "http://kempele.fi/~skyostil/python/fretsonfire/upload")
-Config.define("video",  "fullscreen",   bool,  True,  text = "Fullscreen Mode",      options = {False: "No", True: "Yes"})
+Config.define("video",  "fullscreen",   bool,  False,  text = "Fullscreen Mode",      options = {False: "No", True: "Yes"})
 Config.define("video",  "multisamples", int,   4,     text = "Antialiasing Quality", options = {0: "None", 2: "2x", 4: "4x", 6: "6x", 8: "8x"})
 Config.define("video",  "resolution",   str,   "640x480")
 Config.define("video",  "fps",          int,   80,    text = "Frames per Second", options = dict([(n, n) for n in range(0, 120)]))
