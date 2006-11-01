--- src/GameEngine.py	Wed Nov  1 01:00:46 2006
+++ src/GameEngine.py	Wed Nov  1 01:01:06 2006
@@ -49,7 +49,7 @@
 Config.define("game",   "uploadscores", bool,  False, text = _("Upload Highscores"),    options = {False: _("No"), True: _("Yes")})
 Config.define("game",   "uploadurl",    str,   "http://kempele.fi/~skyostil/python/fretsonfire/upload")
 Config.define("game",   "leftymode",    bool,  False, text = _("Lefty mode"),           options = {False: _("No"), True: _("Yes")})
-Config.define("video",  "fullscreen",   bool,  True,  text = _("Fullscreen Mode"),      options = {False: _("No"), True: _("Yes")})
+Config.define("video",  "fullscreen",   bool,  False,  text = _("Fullscreen Mode"),      options = {False: _("No"), True: _("Yes")})
 Config.define("video",  "multisamples", int,   4,     text = _("Antialiasing Quality"), options = {0: _("None"), 2: _("2x"), 4: _("4x"), 6: _("6x"), 8: _("8x")})
 Config.define("video",  "resolution",   str,   "640x480")
 Config.define("video",  "fps",          int,   80,    text = _("Frames per Second"), options = dict([(n, n) for n in range(0, 120)]))
