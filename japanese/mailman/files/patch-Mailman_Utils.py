--- Mailman/Utils.py.orig	2011-12-11 07:56:23 UTC
+++ Mailman/Utils.py
@@ -1,4 +1,4 @@
-# Copyright (C) 1998-2011 by the Free Software Foundation, Inc.
+# Copyright (C) 1998-2018 by the Free Software Foundation, Inc.
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -93,6 +93,12 @@ def list_exists(listname):
     #
     # The former two are for 2.1alpha3 and beyond, while the latter two are
     # for all earlier versions.
+    #
+    # But first ensure the list name doesn't contain a path traversal
+    # attack.
+    if len(re.sub(mm_cfg.ACCEPTABLE_LISTNAME_CHARACTERS, '', listname)) > 0:
+        syslog('mischief', 'Hostile listname: %s', listname)
+        return False
     basepath = Site.get_listpath(listname)
     for ext in ('.pck', '.pck.last', '.db', '.db.last'):
         dbfile = os.path.join(basepath, 'config' + ext)
@@ -952,6 +958,7 @@ _badwords = [
     '<meta',
     '<object',
     '<script',
+    '@keyframes',
     r'\bj(?:ava)?script\b',
     r'\bvbs(?:cript)?\b',
     r'\bdomactivate\b',
@@ -968,12 +975,14 @@ _badwords = [
     r'\bon(?:de)?activate\b',
     r'\bon(?:after|before)print\b',
     r'\bon(?:after|before)update\b',
+    r'\b(?:on)?animation(?:end|iteration|start)\b',
     r'\bonbefore(?:(?:de)?activate|copy|cut|editfocus|paste)\b',
     r'\bonbeforeunload\b',
     r'\bonbegin\b',
     r'\bonblur\b',
     r'\bonbounce\b',
     r'\bonbroadcast\b',
+    r'\boncanplay(?:through)?\b',
     r'\bon(?:cell)?change\b',
     r'\boncheckboxstatechange\b',
     r'\bon(?:dbl)?click\b',
@@ -989,7 +998,9 @@ _badwords = [
     r'\bondrag(?:drop|end|enter|exit|gesture|leave|over)?\b',
     r'\bondragstart\b',
     r'\bondrop\b',
-    r'\bonend\b',
+    r'\bondurationchange\b',
+    r'\bonemptied\b',
+    r'\bonend(?:ed)?\b',
     r'\bonerror(?:update)?\b',
     r'\bonfilterchange\b',
     r'\bonfinish\b',
@@ -999,21 +1010,28 @@ _badwords = [
     r'\bonkey(?:up|down|press)\b',
     r'\bonlayoutcomplete\b',
     r'\bon(?:un)?load\b',
+    r'\bonloaded(?:meta)?data\b',
+    r'\bonloadstart\b',
     r'\bonlosecapture\b',
     r'\bonmedia(?:complete|error)\b',
+    r'\bonmessage\b',
     r'\bonmouse(?:down|enter|leave|move|out|over|up|wheel)\b',
     r'\bonmove(?:end|start)?\b',
     r'\bon(?:off|on)line\b',
+    r'\bonopen\b',
     r'\bonoutofsync\b',
     r'\bonoverflow(?:changed)?\b',
     r'\bonpage(?:hide|show)\b',
     r'\bonpaint\b',
     r'\bonpaste\b',
     r'\bonpause\b',
+    r'\bonplay(?:ing)?\b',
+    r'\bonpopstate\b',
     r'\bonpopup(?:hidden|hiding|showing|shown)\b',
     r'\bonprogress\b',
     r'\bonpropertychange\b',
     r'\bonradiostatechange\b',
+    r'\bonratechange\b',
     r'\bonreadystatechange\b',
     r'\bonrepeat\b',
     r'\bonreset\b',
@@ -1023,19 +1041,30 @@ _badwords = [
     r'\bonrow(?:delete|enter|exit|inserted)\b',
     r'\bonrows(?:delete|enter|inserted)\b',
     r'\bonscroll\b',
-    r'\bonseek\b',
+    r'\bonsearch\b',
+    r'\bonseek(?:ed|ing)?\b',
     r'\bonselect(?:start)?\b',
     r'\bonselectionchange\b',
+    r'\bonshow\b',
     r'\bonstart\b',
+    r'\bonstalled\b',
     r'\bonstop\b',
+    r'\bonstorage\b',
     r'\bonsubmit\b',
+    r'\bonsuspend\b',
     r'\bonsync(?:from|to)preference\b',
     r'\bonsyncrestored\b',
     r'\bontext\b',
-    r'\bontimeerror\b',
+    r'\bontime(?:error|update)\b',
+    r'\bontoggle\b',
+    r'\bontouch(?:cancel|end|move|start)\b',
     r'\bontrackchange\b',
+    r'\b(?:on)?transitionend\b',
     r'\bonunderflow\b',
     r'\bonurlflip\b',
+    r'\bonvolumechange\b',
+    r'\bonwaiting\b',
+    r'\bonwheel\b',
     r'\bseeksegmenttime\b',
     r'\bsvgabort\b',
     r'\bsvgerror\b',
