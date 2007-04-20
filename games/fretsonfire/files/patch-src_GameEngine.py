--- src/GameEngine.py	Sat Apr  7 03:11:34 2007
+++ src/GameEngine.py	Fri Apr 20 14:43:01 2007
@@ -52,7 +52,7 @@
 Config.define("game",   "uploadurl",    str,   "http://kempele.fi/~skyostil/python/fretsonfire/upload")
 Config.define("game",   "leftymode",    bool,  False, text = _("Lefty mode"),           options = {False: _("No"), True: _("Yes")})
 Config.define("game",   "tapping",      bool,  True,  text = _("Tappable notes"),       options = {False: _("No"), True: _("Yes")})
-Config.define("video",  "fullscreen",   bool,  True,  text = _("Fullscreen Mode"),      options = {False: _("No"), True: _("Yes")})
+Config.define("video",  "fullscreen",   bool,  False,  text = _("Fullscreen Mode"),      options = {False: _("No"), True: _("Yes")})
 Config.define("video",  "multisamples", int,   4,     text = _("Antialiasing Quality"), options = {0: _("None"), 2: _("2x"), 4: _("4x"), 6: _("6x"), 8: _("8x")})
 Config.define("video",  "resolution",   str,   "640x480")
 Config.define("video",  "fps",          int,   80,    text = _("Frames per Second"), options = dict([(n, n) for n in range(1, 120)]))
